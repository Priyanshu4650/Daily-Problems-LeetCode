class Solution {
public:
    string removeOuterParentheses(string s) {
        int st = 0;
        int end = 0;
        int curr = 0;
        vector<pair<int, int>> indices;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(') {
                curr += 1;
            }
            else {
                curr -= 1;
            }

            if(curr == 0) {
                end = i;
                indices.push_back({st, end});
                st = i + 1;
            }
        }

        for(int i=0;i<indices.size();i++) {
            cout << indices[i].first << " " << indices[i].second << endl;
        }

        string res = "";
        for(int i=0;i<indices.size();i++) {
            res += s.substr(indices[i].first + 1, indices[i].second - indices[i].first - 1);
        }
        
        return res;
    }
};