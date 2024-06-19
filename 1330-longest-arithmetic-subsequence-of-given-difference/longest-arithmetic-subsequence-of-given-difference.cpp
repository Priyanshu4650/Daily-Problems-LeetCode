class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int res = 0;

        for(auto num : arr) {
            int k = num - difference;

            if(mp.find(num - difference) != mp.end()) {
                mp[num] = 1 + mp[num - difference];
            }
            else {
                mp[num] = 1;
            }

            res = max(res, mp[num]);
        }

        for(auto it : mp) {
            cout << it.first << " " << it.second << endl;
        }

        return res;
    }
};