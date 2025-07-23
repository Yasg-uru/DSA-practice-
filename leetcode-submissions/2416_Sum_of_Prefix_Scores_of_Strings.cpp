class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            string prefix="";
            for(char ch:words[i]){
                prefix+=ch;
                mp[prefix]++;
            }
        }
        vector<int>ans(words.size());
        for(int i=0;i<words.size();i++){
            string prefix="";
            int count=0;
            for(char ch:words[i]){
                prefix+=ch;
                if(mp.find(prefix)!=mp.end()){
                    count+=mp[prefix];
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};