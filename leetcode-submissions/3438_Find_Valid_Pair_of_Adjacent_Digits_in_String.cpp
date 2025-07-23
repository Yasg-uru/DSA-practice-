class Solution {
public:
    string findValidPair(string s) {
        unordered_map<int,int>mp;
        for(int i=0;i<s.length();i++){
            int num = s[i]-'0';
            mp[num]++;
        }
        string ans ="";
        for(int i=0;i<s.size()-1;i++){
           if (mp[s[i] - '0'] == (s[i] - '0') && mp[s[i + 1] - '0'] == (s[i + 1] - '0') && s[i]!=s[i+1]) {
                ans = string(1, s[i]) + string(1, s[i + 1]);
                break;
            }
        }
        cout<<"this is ans:"<<ans;
        return ans ;
    }
};