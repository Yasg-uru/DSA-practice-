class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        while(t--){
            for(int i =0 ;i<s.length();i++){
                if(s[i]=='z'){
                    s.replace(i , 1 , "ab");
                    continue;
                }
                s[i] = (char)s[i]+1;
            }

        }
        return s.length();
    }
};