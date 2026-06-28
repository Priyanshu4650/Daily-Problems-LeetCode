class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        int count = 0;

        for(int i=1;i<nums.size();i++) {
            prefixSum[i] += prefixSum[i - 1] + nums[i];
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                long long sum = prefixSum[i] - (j > 0 ? prefixSum[j - 1] : 0);

                // cout << "Sum from " << i << " to " << j << " is " << sum << endl;

                // string tostr = to_string(abs(sum));

                // cout << tostr << " is the string\n";

                long long val = abs(sum);

                int lastDigit = val % 10;

                while (val >= 10) {
                    val /= 10;
                }

                int firstDigit = val;

                // cout << firstDigit << " " << lastDigit << endl;

                if(firstDigit == x && lastDigit == x) {
                    // cout << "Did I come here?\n";
                    count += 1;
                }
            }
        }

        return count;
    }
};