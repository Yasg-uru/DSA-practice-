class Solution {
public:
    bool areOccurrencesEqual(string s) {
        if(s.empty()){
            return true ;
        }
       unordered_map<char , int>mp;
       for(char ch :s){
        mp[ch]++;
       } 
       int picked = mp[s[0]];
       for(int i =1 ;i<s.length();i++){
        if(mp[s[i]]!=picked){
            return false;
        }
       }
       return true ;
    }
};