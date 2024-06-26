class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        // Array to store minimum jumps required to reach each index
        vector<int> minJumps(n, INT_MAX);
        minJumps[0] = 0; // Starting point
        
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                if (i + j < n) {
                    minJumps[i + j] = min(minJumps[i + j], minJumps[i] + 1);
                }
            }
        }
        
        return minJumps[n - 1];
    }
};
