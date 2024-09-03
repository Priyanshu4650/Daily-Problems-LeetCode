class Solution {
public:
    int getLucky(string s, int k) {
        string converted = "";
        
        for(int i=0;i<s.size();i++) {
            converted += to_string(s[i] - 'a' + 1);
        }
        s = converted;
        converted = "";

        while(k > 1) {
            int sum = 0;
            for(int i=0;i<s.size();i++)
                sum += (s[i] - '0');
            
            s = to_string(sum);
            k -= 1;
        }

        int sum = 0;
        for(int i=0;i<s.size();i++) {
            sum += (s[i] - '0');
        }

        return sum;
    }
};