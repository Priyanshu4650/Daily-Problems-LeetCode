class Solution {
public:
    string lexSmallest(string s) {
        string smallest = s;

        for(int i=1;i<=s.size();i++) {
            string pre = s.substr(0, i);
            string suff = s.substr(i, s.size() - i);

            string first = pre;
            reverse(first.begin(), first.end());
            first += suff;

            if(first < smallest) 
                smallest = first;
            
            string second = suff;
            reverse(second.begin(), second.end());
            second = pre + second;

            if(second < smallest) 
                smallest = second;
            
            // cout << pre << " " << suff << " " << first << " " << second << " " << i << endl;
        }

        return smallest;
    }
};