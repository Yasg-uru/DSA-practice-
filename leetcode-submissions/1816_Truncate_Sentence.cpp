class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string word ;
        string ans = "";
        int cnt = 0 ;

        while(ss >> word){
            if(cnt==k){
                break;
            }
            cnt++;
            ans+=word;
            ans+=" ";
        }
        ans.pop_back();
        return ans ;
    }
};