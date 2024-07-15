class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) 
            return "";
        
        unordered_map<char, int> freqT;
        for (char c : t) {
            freqT[c]++;
        }
        
        int n = s.size();
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int startInd = 0;
        int required = t.size();
        
        unordered_map<char, int> freqWindow;
        
        while (r < n) {
            // Expand the window to the right
            if (freqT.find(s[r]) != freqT.end()) {
                freqWindow[s[r]]++;
                if (freqWindow[s[r]] <= freqT[s[r]]) {
                    required--;
                }
            }
            
            // Contract the window from the left if all characters are found
            while (required == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startInd = l;
                }
                
                if (freqT.find(s[l]) != freqT.end()) {
                    freqWindow[s[l]]--;
                    if (freqWindow[s[l]] < freqT[s[l]]) {
                        required++;
                    }
                }
                
                l++;
            }
            
            r++;
        }
        
        if (minLen == INT_MAX) {
            return "";
        }
        
        return s.substr(startInd, minLen);
    }
};
