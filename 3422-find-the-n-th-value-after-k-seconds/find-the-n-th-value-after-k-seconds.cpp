class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<long long> pre(n, 1);

        for(int i=0;i<k;i++) {
            for(int i=1;i<n;i++) {
                pre[i] = pre[i-1] % 1000000007 + pre[i] % 1000000007;
            }
        }

        return pre[n - 1] % 1000000007;
    }
};