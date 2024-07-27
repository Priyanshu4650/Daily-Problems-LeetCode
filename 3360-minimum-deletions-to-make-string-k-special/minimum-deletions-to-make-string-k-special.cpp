class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        for (auto it : word) {
            mp[it]++;
        }

        vector<int> freq;
        for (auto it : mp) {
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = INT_MAX;

        for (int i = 0; i < freq.size(); i++) {
            int num = freq[i];
            int cnt = 0;

            for (int j = 0; j < freq.size(); j++) {
                if (freq[j] - num > k) {
                    cnt += freq[j] - (num + k);
                } else if (num > freq[j]) {
                    cnt += freq[j];
                }
            }
            ans = min(ans, cnt);
            if (cnt == 0) {
                break;
            }
        }

        return ans;
    }
};
