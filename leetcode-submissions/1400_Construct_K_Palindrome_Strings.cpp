class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k){
            return false;
        }
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int oddCount =0;
        for(auto ele :mp){
if(ele.second%2){
    oddCount++;
}
        }
        return oddCount<=k;
    }
};