class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastIndex(26,-1);
        vector<bool>isTaken(26, false);
        for(int i=0;i<s.length();i++){
           char ch = s[i];
            lastIndex[ch-'a']= i;
        }
        string result ="";
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(isTaken[ch-'a']){
                continue ;
            }
            while(result.length()>0 and result.back()>ch and lastIndex[result.back()-'a']>i){
                isTaken[result.back()-'a']=false;
                result.pop_back();
            }
            isTaken[ch-'a']= true ;
            result.push_back(ch);
        }
        return result ;

    }
};