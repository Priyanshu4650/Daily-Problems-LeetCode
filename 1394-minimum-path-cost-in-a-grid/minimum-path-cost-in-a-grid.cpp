class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>test(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            test[0][i]=grid[0][i];
        }
        int ans=1e5;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int curr=grid[i][j];
                int mini=1e5;
                for(int k=0;k<m;k++){
                    if((cost[grid[i-1][k]][j]+test[i-1][k]+curr)<mini){
                        mini=(cost[grid[i-1][k]][j]+curr+test[i-1][k]);
                        test[i][j]=mini;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            ans=min(ans,test[n-1][i]);
        }
        return ans;
    }
};