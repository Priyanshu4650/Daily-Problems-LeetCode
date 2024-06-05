class Solution {
public:
    string compressedString(string s) 
    {
        string ans;
        char back = s[0];
        int i = 0, cnt = 0;
        while(s[i])
        {
            while(s[i] == back)
            {
                cnt++;
                if(cnt == 9)
                {
                    ans += '9';
                    ans += back;
                    cnt = 0;
                }
                i++;
            }
            if(cnt)
            {
                ans += to_string(cnt);
                ans += back;
            }
            cnt = 0;
            back = s[i];
        } 
        return ans;
    }
};