#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val, freq;
    bool operator<(const Node& other) const {
        if (freq == other.freq) return val > other.val;
        return freq > other.freq;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        using ll = long long;
        int n = nums.size();
        vector<ll> ans(n - k + 1);

        unordered_map<ll, ll> freq;
        freq.reserve(k * 2);

        auto cmp = [](const Node& a, const Node& b) {
            if (a.freq == b.freq) return a.val > b.val;
            return a.freq > b.freq;
        };

        multiset<Node, decltype(cmp)> top(cmp), rest(cmp);
        ll currentSum = 0;

        auto balance = [&]() {
            // Ensure top has at most x elements
            while ((int)top.size() > x) {
                auto it = prev(top.end());
                rest.insert(*it);
                currentSum -= it->val * it->freq;
                top.erase(it);
            }
            while ((int)top.size() < x && !rest.empty()) {
                auto it = rest.begin();
                currentSum += it->val * it->freq;
                top.insert(*it);
                rest.erase(it);
            }
        };

        auto insertVal = [&](ll val) {
            ll old = freq[val]++;
            if (old > 0) {
                Node node{val, old};
                if (auto it = top.find(node); it != top.end()) {
                    currentSum -= val * old;
                    top.erase(it);
                } else if (auto it2 = rest.find(node); it2 != rest.end()) {
                    rest.erase(it2);
                }
            }
            Node updated{val, freq[val]};
            rest.insert(updated);
            // move best element if needed
            if (!rest.empty() && (int)top.size() < x) {
                auto it = rest.begin();
                currentSum += it->val * it->freq;
                top.insert(*it);
                rest.erase(it);
            } else if (!rest.empty() && *rest.begin() < *prev(top.end())) {
                // swap if rest has a better candidate
                auto worst = prev(top.end());
                auto best = rest.begin();
                currentSum += best->val * best->freq - worst->val * worst->freq;
                top.insert(*best);
                rest.insert(*worst);
                rest.erase(best);
                top.erase(worst);
            }
            balance();
        };

        auto removeVal = [&](ll val) {
            ll old = freq[val]--;
            Node node{val, old};
            if (auto it = top.find(node); it != top.end()) {
                currentSum -= val * old;
                top.erase(it);
            } else if (auto it2 = rest.find(node); it2 != rest.end()) {
                rest.erase(it2);
            }
            if (freq[val] > 0) {
                Node updated{val, freq[val]};
                rest.insert(updated);
            } else freq.erase(val);
            balance();
        };

        for (int i = 0; i < k; i++) insertVal(nums[i]);
        ans[0] = currentSum;

        for (int i = k; i < n; i++) {
            removeVal(nums[i - k]);
            insertVal(nums[i]);
            ans[i - k + 1] = currentSum;
        }

        return ans;
    }
};
