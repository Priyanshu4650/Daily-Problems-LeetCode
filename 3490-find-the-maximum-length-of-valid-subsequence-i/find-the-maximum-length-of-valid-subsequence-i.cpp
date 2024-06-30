class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int con1 = 0, con2 = 0, con3 = 0, con4 = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] % 2 == 0)
                con1 += 1;
        }
        for(int i=0;i<n;i++) {
            if(nums[i] % 2 == 1)
                con2 += 1;
        }

        int startOdd = 1;
        for(int i=0;i<n;i++) {
            if(nums[i] % 2 == startOdd) {
                con3 += 1;
                startOdd = 1 - startOdd;
            }
        }

        startOdd = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] % 2 == startOdd) {
                con4 += 1;
                startOdd = 1 - startOdd;
            }
        }

        return max(con1, max(con2, max(con3, con4)));
    }
};