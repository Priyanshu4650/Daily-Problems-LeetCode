class Solution {
    unordered_set<string> oper = {"+", "-", "/", "*"};
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token : tokens) {
            if(oper.find(token) != oper.end()) {
                int n = st.top();
                st.pop();
                int m = st.top();
                st.pop();

                if(token == "+") {
                    st.push(n + m);
                }
                else if(token == "-") {
                    st.push(m - n);
                }
                else if(token == "/") {
                    st.push(m / n);
                }
                else if(token == "*") {
                    st.push(n * m);
                }
            }
            else {
                st.push(atoi(token.c_str()));
            }

            cout << st.top() << " " << st.size() << endl;
        }

        return st.top();
    }
};