class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int result = 0;
        int maxScore = 0;

        for(auto divisor : divisors) {
            int currScore = 0;
            for(auto num : nums) {
                if(num % divisor == 0) 
                currScore += 1;
            }

            if(currScore > maxScore) {
                result = divisor;
            }
            else if(currScore == maxScore) {
                result = min(result, divisor);
            }

            maxScore = max(maxScore, currScore);
        }

        return result == 0 ? *min_element(divisors.begin(), divisors.end()) : result;
    }
};