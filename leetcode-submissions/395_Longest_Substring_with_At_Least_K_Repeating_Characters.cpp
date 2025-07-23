class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int>mp;
        for(char ele:s){
            mp[ele]++;
        }
        int ans=0;
        for(auto ele:mp){
            if(ele.second>=k){
                ans+=ele.second;
            }
     
    }
     return ans;  
      }
};