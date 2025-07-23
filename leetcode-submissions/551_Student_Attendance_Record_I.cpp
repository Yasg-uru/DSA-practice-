class Solution {
public:
    bool checkRecord(string s) {
       unordered_map<char,int>mp;
       for(int i=0;i<s.size();i++){
           mp[s[i]]++;
       } 
       bool ans=true;
       if(mp.find('A')!=mp.end() ){
           if(mp['A']<1){
               ans=false;
           }
       }
       if(mp.find('L')!=mp.end()){
           if(mp['L']>2){
ans=false;
           }
       }
       return ans;
    }
};