class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> vis;
        for(int i=0;i<n;i++){
            vis.insert(i);
        }
        int dist = n-1; //intial configuration
        vector<int> ans;
       
        for(auto &vec:queries){
            int x = vec[0], y = vec[1];
            if(vis.find(x)==vis.end()){
                //continue;
            }
            else{
                if(vis.find(y)==vis.end()){
                    //continue;
                }
                else{
                    int st = x+1;
                    int end = y-1;
                    
                    auto it = vis.find(x);
                    it++;
                    while( *it <= end ){
                        auto save = it; save++;
                        vis.erase(it);
                        dist--;
                        it = save;                        
                    }
                }
            }
            ans.push_back(dist);
        }
        return ans;
    }
};