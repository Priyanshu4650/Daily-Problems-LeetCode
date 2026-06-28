class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;

        for(int i=0;i<m;i++) {
            string curr = "";
            for(int j=0;j<n;j++){
                if(i == 0) {
                    curr += '.';
                }
                else {
                    if(j == n - 1) {
                        curr += '.';
                    }
                    else {
                        curr += '#';
                    }
                }
            }
            res.push_back(curr);
        }

        for(auto temp : res) {
            cout << temp << endl;
        }

        // for(int i=1;i<m;i++) {
        //     for(int j=0;j<n-1;j++) {
        //         res[i][j] = '#';
        //     }
        //     break;
        // }

        return res;
    }
};