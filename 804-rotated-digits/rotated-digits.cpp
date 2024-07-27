class Solution {
public:
    string rotate(string s){
        string temp="";
        bool check=true;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0' || s[i]=='1' || s[i]=='8'){
                temp+=s[i];
            }
            else if(s[i]=='2'){
                temp+='5';
            }
            else if(s[i]=='5'){
                temp+='2';
            }
            else if(s[i]=='6'){
                temp+='9';
            }
            else if(s[i]=='9'){
                temp+='6';
            }
            else{
                check=false;
                break;
            }
        }
        if(check==false){
            return "-1";
        }
        return temp;
    }
    int rotatedDigits(int n) {
        int count=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            string check=rotate(s);
            if(s!=check && check!="-1"){
                count++;
            }
        }
        return count;
    }
};