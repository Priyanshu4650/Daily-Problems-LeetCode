class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), [](int a, int b) {
            return a > b;
        });

        long long sum = maximumHeight[0];
        unordered_set<int> s = {maximumHeight[0]};
        for(int i=1;i<maximumHeight.size();i++) {
            
            // while(s.find(maximumHeight[i]) != s.end()) {
            //     maximumHeight[i] -= 1;
            // }

            // if(maximumHeight[i] <= 0) {
            //     return -1;
            // }

            // s.insert(maximumHeight[i]);
            maximumHeight[i] = min(maximumHeight[i], maximumHeight[i - 1] - 1);
            if(maximumHeight[i] <= 0)
                return -1;
            sum += maximumHeight[i];
        }

        return sum;
    }
};