class Solution {
public:
    string addStrings(string s, string t) {
        int carry = 0;
        string result = "";
        int i = s.size() - 1;
        int j = t.size() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += s[i--] - '0';
            }
            if (j >= 0) {
                sum += t[j--] - '0';
            }
            carry = sum / 2;
            result = to_string(sum % 2) + result;
        }
        return result;
    }

    int numSteps(string s) {
        int count = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();
            } else {
                s = addStrings(s, "1");
            }
            count++;
        }
        return count;
    }
};
