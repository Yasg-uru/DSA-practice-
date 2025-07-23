class Solution {
public:
    string shift(string s , int character_count , int shifts){
        for(int i =0 ;i<character_count;i++){
            s[i] = (s[i]-'a'+shifts)%26+'a' ;
        }
        return s;
    }
    string shiftingLetters(string s, vector<int>& shifts) {
       for(int i =0 ;i<s.length();i++){
        s = shift(s, i+1, shifts[i]);
       }
       return s;
    }
    
};