class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        long long duble = 0;
        long long single = 0;
        
        int n = nums.size();
        for(int i=0;i<n;i++) {
            string curr = to_string(nums[i]);
            if(curr.size() == 2) {
                duble += nums[i];
            }
            else {
                single += nums[i];
            }
        }

        return duble != single;
    }
};