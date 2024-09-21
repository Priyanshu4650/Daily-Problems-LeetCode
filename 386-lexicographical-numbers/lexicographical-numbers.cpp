class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> num(n);
        for(int i=1;i<=n;i++) {
            num[i - 1] = i;
        }

        sort(num.begin(), num.end(), [](int a, int b){    
            return to_string(a) < to_string(b);
        });

        return num;
    }
};