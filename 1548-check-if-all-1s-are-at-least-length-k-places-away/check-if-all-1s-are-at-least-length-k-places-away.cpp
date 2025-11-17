class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int firstInd = -1;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 1) {
                if(firstInd == -1) {
                    firstInd = i;
                }
                else {
                    if(i - firstInd - 1 < k) {
                        return false;
                    } 
                    firstInd = i;
                }
            }
        }
        
        return true;
    }
};