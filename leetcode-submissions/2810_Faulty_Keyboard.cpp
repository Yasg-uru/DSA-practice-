class Solution {
public:
    string finalString(string s) {
        string ans="";
        int i=0;
        while(i<s.size()){
            if(s[i]=='i'){
                reverse(ans.begin(),ans.end());
                i++;
            }else{
                ans+=s[i];
                i++;
            }
        }
return ans;
    }
};