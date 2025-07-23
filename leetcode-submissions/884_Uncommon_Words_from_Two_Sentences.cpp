class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        unordered_map<string,int>mp;
       string s=s1+" "+s2;
       stringstream str(s);
       string word;
       while(str>>word){
        mp[word]++;
       }
       for(const auto & ele:mp){
        if(ele.second==1){
            ans.push_back(ele.first);
        }
       }
       return ans;

    }
};