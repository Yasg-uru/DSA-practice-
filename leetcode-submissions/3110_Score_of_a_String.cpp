class Solution {
public:
    int scoreOfString(string s) {
        //now calculating the ascii value of the charcters and then adding it
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            int a =s[i]-'a';
            int b=s[i+1]-'a';
            ans+=abs(a-b);
        }
        return ans;
    }
};