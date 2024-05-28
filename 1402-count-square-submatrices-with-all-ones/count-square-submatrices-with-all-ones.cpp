class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int res = 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            if(mat[i][0] == 1){
                dp[i][0] = 1;
                res++;
            }
        }
        
        for(int i=1;i<m;i++)
        {
            if(mat[0][i] == 1){
                dp[0][i] = 1;
                res++;
            }
        }
        
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j] == 1){
                    dp[i][j] = 1+ min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
                }
                    res+=dp[i][j];                
                
            }
        }
        
        return res;
    }
};