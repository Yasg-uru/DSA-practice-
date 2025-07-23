class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        vector<int>f1(128,-1);
        vector<int>f2(128,-1);
        for(int i=0;i<s.size();i++){
            if(f1[s[i]]!=f2[t[i]]){
                return false;
            }
            f1[s[i]]=f2[t[i]]=i;
        }
        return true;
    }
};