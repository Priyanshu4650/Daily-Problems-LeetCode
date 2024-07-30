class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> product(n + m, 0);

        if (num1 == "0" || num2 == "0") return "0";

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + product[i + j + 1];

                product[i + j + 1] = sum % 10;     
                product[i + j] += sum / 10;        
            }
        }

        string result = "";
        bool leadingZero = true;
        for (int num : product) {
            if (num != 0) leadingZero = false;
            if (!leadingZero) result += to_string(num);
        }

        return result.empty() ? "0" : result;
    }
};