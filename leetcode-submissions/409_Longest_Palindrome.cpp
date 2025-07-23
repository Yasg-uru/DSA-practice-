class Solution {
public:
    bool iseven(int n){
        return (n%2==0);
    }
    int longestPalindrome(string s) {
        if(s.size()==1){
            return 1;
        }
        int ans=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto ele:mp){
            if(ele.second%2==0){
                ans+=ele.second;
            }
        }
        for(auto ele:mp){
            if(ele.second%2!=0){
                ans+=1;
                break;
            }
        }
        return ans;
    }
};