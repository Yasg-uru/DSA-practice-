class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        unordered_map<char , int >mp;
        for(char ch :s){
            mp[ch]++;
        }
        int picked = mp[s[0]];
        
        for(auto& ele : mp){
            if(picked!=ele.second){
                return false;
            }
        }
        return true ;
    }
};