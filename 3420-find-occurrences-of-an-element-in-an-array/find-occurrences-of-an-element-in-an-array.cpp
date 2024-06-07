class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> occur;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == x) {
                occur.push_back(i);
            }
        }
        vector<int> res;
        for(int i=0;i<queries.size();i++) {
            if(queries[i] > occur.size()) 
                res.push_back(-1);
            else 
                res.push_back(occur[queries[i]-1]);
        }
        return res;
    }
};