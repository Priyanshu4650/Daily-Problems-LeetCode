class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> data(names.size());
        for(int i=0;i<names.size();i++) {
            data[i].first = heights[i];
            data[i].second = names[i];
        }

        sort(data.begin(), data.end());

        vector<string> res;
        for(int i=data.size() - 1;i>=0;i--) {
            res.push_back(data[i].second);
        }

        return res;
    }
};