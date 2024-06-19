class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int ans=1;
        while(n)
        {
            if(n-3>=2)
            {
                ans*=3;
                n-=3;
            }
            else 
            {
                ans*=n;
                n-=n;
            }
        }
        return ans;
    }
};