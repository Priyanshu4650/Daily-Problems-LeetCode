class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> arr(n, 0);

        for(int i=0;i<s.size();i++) {
            arr[i] = abs(s[i] - t[i]);
        }
        
        for(int i=0;i<n;i++) 
            cout << arr[i] << " ";
        cout << endl;

        int res = 0;
        int currSum = 0;

        int i = 0;
        int j = 0;

        while(j < n) {
            if(currSum <= maxCost) {
                res = max(res, j - i);
                currSum += arr[j];
                j += 1;
            }
            else {
                currSum -= arr[i];
                i += 1;
            }
            cout << i << " " << j << " " << currSum << " " << res << endl;
        }

        if(currSum <= maxCost) {
            res = max(res, j - i);
        }

        return res;
    }
};