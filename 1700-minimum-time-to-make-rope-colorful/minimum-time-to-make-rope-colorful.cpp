class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = neededTime[0];
        int res = 0;
        int currMax = neededTime[0];

        for(int i=1;i<colors.size();i++){
            if(colors[i] == colors[i-1]){
                sum += neededTime[i];
                currMax = max(currMax, neededTime[i]);
            }
            else{
                res += sum - currMax;
                sum = neededTime[i];
                currMax = neededTime[i];
            }
            // cout << colors[i] << " " << neededTime[i] << " " << sum << " " << currMax << " " << res << endl;
        }

        if(sum != currMax){
            res += sum - currMax;
        }

        return res;
    }
};