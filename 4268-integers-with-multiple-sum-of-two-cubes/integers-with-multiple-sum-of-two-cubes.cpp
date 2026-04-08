class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> seen;
        int n3 = cbrt(n);
        vector<int> ans;
        for(int x=1; x<=n3; x++){
            int a3=x*x*x, yN=cbrt(n-a3);
            for(int y=x+1; y<=yN+1; y++){
                int sum=a3+y*y*y;
                if (sum>n) break;
                if(seen[sum]==1)
                    ans.push_back(sum);
                seen[sum]++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};