class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        vector<long long> res;
        
        for(auto num: nums) {
            long long valueToInsert = num;
            while(!st.empty() && st.top() == valueToInsert) {
                st.pop();
                valueToInsert *= 2;
            }
            st.push(valueToInsert);
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};