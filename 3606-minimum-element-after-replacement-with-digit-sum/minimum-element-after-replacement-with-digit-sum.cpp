class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;

        for(auto num : nums) {
            string n = to_string(num);
            int currSum = 0;

            for(int i=0;i<n.size();i++) {
                currSum += n[i] - '0';
            }

            result = min(result, currSum);
        }

        return result;
    }
};