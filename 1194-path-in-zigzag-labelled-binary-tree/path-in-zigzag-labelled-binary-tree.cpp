class Solution {
public:
    vector<int> pathInZigZagTree(int k) {
        int lvl = log(k) / log(2) + 1;
        vector<int>v(lvl);  

        while(k)
        {
            v[lvl-1]=k;

            k= (1<<lvl)-1 + (1<<(lvl-1)) - k ;
            k>>=1;
            lvl--;
        }
        return v;
    }
};