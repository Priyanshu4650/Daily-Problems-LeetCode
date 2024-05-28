class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> indices;
        int currSign = groups[0];
        indices.push_back(0);

        int i = 0;
        int n = groups.size();

        while(i < n) {
            if(currSign == groups[i]) {
                i += 1;
            }
            else {
                indices.push_back(i);
                currSign = groups[i];
                i += 1;                
            }
        }

        vector<string> res(indices.size(), "");
        for(i=0;i<indices.size();i++) {
            res[i] = words[indices[i]];
        }

        return res;
    }
};