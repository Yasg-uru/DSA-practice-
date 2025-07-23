class Solution {
public:
    char findTheDifference(string s, string t) {
        //we need to make map for storinig characters frequency of s string
        char ans;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(!mp.count(t[i])){
               ans=t[i];
               break;
            }
        }
       return ans;
    }
};