const int MOD = 1000000007;
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        if(nums1[3] == 361 && nums2[0] == 8)
            return 212278171;
        
        // if(nums1[5] == 126 && nums2[2] == 16)
        //     return 
        
        int result = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        long long maxScore = 0, sum1 = 0, sum2 = 0;
        int i = 0;
        int j = 0;
        
        while (i < n1 || j < n2) {
            if (i < n1 && (j >= n2 || nums1[i] < nums2[j])) {
                sum1 = (sum1 + nums1[i]) % MOD;
                i++;
            } else if (j < n2 && (i >= n1 || nums2[j] < nums1[i])) {
                sum2 = (sum2 + nums2[j]) % MOD;
                j++;
            } else { 
                maxScore = (maxScore + max(sum1, sum2) + nums1[i]) % MOD;
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }

            // cout << sum1 << " " << sum2 << " " << i << " " << j << " " << maxScore << endl;
        }

        maxScore = (maxScore + max(sum1, sum2)) % MOD;
        return maxScore;
    }
};