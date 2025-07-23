class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int diff =0 ;
        for(int i =0 ;i<s1.length();i++){
            if(s1[i]==s2[i]) continue ;
            
            diff++;
        }
        return diff-1;
    }
};