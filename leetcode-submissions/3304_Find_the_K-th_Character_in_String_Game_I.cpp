class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.length()<=k){
            int n = s.length();
            for(int i =0 ;i<n;i++){
                s.push_back((char)(s[i]+1));
            }
            
        }
        return s[k-1];

    }
};