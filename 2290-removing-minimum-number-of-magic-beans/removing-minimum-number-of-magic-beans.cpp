#define ll long long 
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        ll n = beans.size();

        ll sum = accumulate(beans.begin(), beans.end(), 0ll);
        ll result = sum - n * beans[0];

        for(int i=1;i<n;i++) {
            result = min(result, sum - (ll)(n - i) * beans[i]);
        }

        return result;
    }
};