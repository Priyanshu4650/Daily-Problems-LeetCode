class Solution {
public:
    vector<int> findLeaves(int n) {
    vector<int> leaves;
    for (int i = n/2 + 1; i <= n; i++) {
        leaves.push_back(i);
    }
    return leaves;
}
    int minIncrements(int n, vector<int>& cost) {
        vector<int>leaves=findLeaves(n);
        queue<int>q;
        map<int,int>mp;
        for(auto child:leaves){
            mp[child]=0;
            q.push(child);
        }
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                if(curr==1)
                    return ans;
                q.pop();
                int parent;
                if(curr&1){
                    parent=(curr-1)/2;
                }else {
                    parent=curr/2;
                }
                if(parent>0 && mp.count(parent)==0){
                    mp[parent]=mp[curr]+cost[curr-1];
            
                    q.push(parent);
                }else{
                    ans+=abs(mp[parent]-(mp[curr]+cost[curr-1]));
                    mp[parent]=max(mp[parent],mp[curr]+cost[curr-1]);

                }
       
                
                
            }
        }
        return ans;
    }
};