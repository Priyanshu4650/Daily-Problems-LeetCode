class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> freqVec(mp.begin(), mp.end());

        auto comparator = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };

        sort(freqVec.begin(), freqVec.end(), comparator);

        vector<int> result;
        for (auto& it : freqVec) {
            result.insert(result.end(), it.second, it.first);
        }

        return result;
    }
};