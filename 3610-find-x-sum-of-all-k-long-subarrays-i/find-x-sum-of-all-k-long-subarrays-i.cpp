class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        int n = nums.size();

        for(int i=0;i<n-k+1;i++) {
            unordered_map<int, int> freq;
            for(int j=i;j<i+k;j++) {
                freq[nums[j]] += 1;
            }

            vector<pair<int, int>> temp;
            for(auto it: freq) {
                temp.push_back({it.first, it.second});
            }

            sort(temp.begin(), temp.end(), [](auto &a, auto &b){
                if(a.second == b.second) {
                    return a.first > b.first;
                }
                return a.second > b.second;
            });

            int sum = 0;
            for(int i=0;i<x && i < temp.size();i++) {
                sum += temp[i].first * temp[i].second;
            }

            res.push_back(sum);
        } 

        return res;
    }
};