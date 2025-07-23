class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
       char ch;
        for(auto ele:mp){
            if(ele.second==1){
                ch=ele.first;
            }
        }
        int ans=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]==ch){
                ans=i;
            }
        }
        return ans;
    }
};