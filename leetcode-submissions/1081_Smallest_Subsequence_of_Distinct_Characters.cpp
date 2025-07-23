class Solution {
public:
    string smallestSubsequence(string s) {
       vector<int>lastIndex(26,-1);
       vector<bool>isTaken(26, false);
        for(int i=0;i<s.size();i++){
            lastIndex[s[i]-'a']=i;
        }
        string result = "";
        for(int i=0;i<s.size();i++){
            if(isTaken[s[i]-'a']) continue;
            while(not result.empty() and result.back()>s[i] and lastIndex[result.back()-'a']>i){
               isTaken[result.back()-'a']=false;
                result.pop_back();

            }
            isTaken[s[i]-'a']=true ;
            result+=s[i];
        }
        return result;
    }
};