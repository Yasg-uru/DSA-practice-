class Solution {
public:
     string shift(string s , int character_count , int shifts){
        for(int i =0 ;i<character_count;i++){
            s[i] = (s[i]-'a'+shifts)%26+'a' ;
        }
        return s;
    }
    string replaceDigits(string s) {
        for(int  i =0 ;i<s.length();i++){
            if(isdigit(s[i]) and i>0 ){
                int c = (int)s[i]-'0';
                s[i] = (s[i-1]-'a'+c)%26+'a';
            }
        }
        return s;
    }
};