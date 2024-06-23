class Solution {
public:
    string interpret(string command) {
        string res = "";
        int n = command.size();
        int i = 0;
        while(i < n) {
            if(command[i] == '(') {
                if(i + 1 < n) {
                    if(command[i + 1] == ')') {
                        res += 'o';
                        i += 2;
                    }
                    else {
                        res += "al";
                        i += 4;
                    }
                }
            }
            else {
                res.push_back(command[i++]);
            }
        }
        return res;
    }
};