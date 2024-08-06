class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i+1];
            if(i+1 < s.length()){
                int grouped_message = (10*(s[i]-'0') + (s[i+1]-'0'));
                dp[i] = grouped_message>=10 && grouped_message <= 26 ? dp[i] + dp[i+2] : dp[i];
            }
        }
        return dp[0];
    }
};