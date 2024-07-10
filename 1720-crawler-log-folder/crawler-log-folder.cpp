class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(auto log : logs) {
            if(log == "./") {
                continue;
            }
            else if(log == "../") {
                count -= 1;
                if(count < 0) {
                    count = 0;
                }
            }
            else {
                count += 1;
            }
        }
        return count;
    }
};