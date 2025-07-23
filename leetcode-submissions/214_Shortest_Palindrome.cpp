class Solution {
public:
    string shortestPalindrome(string s) {
        int i=0;
        for(int j=s.size()-1;j>=0 ;j--){
            if(s[i]==s[j]){
                i++;
            }
        }
        if(i==s.size()){
            return s;
        }
        //cecaaa
        string t=s.substr(i,s.size());
        reverse(t.begin(),t.end());
        //aaaec + "aa"+"cecaaa"
        return t+shortestPalindrome(s.substr(0,i))+s.substr(i);
    }
};