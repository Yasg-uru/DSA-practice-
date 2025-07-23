class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int>mp;
        string word;
        istringstream iss(paragraph);
        while(iss>>word){
           mp[word]++;
        }
        unordered_set<string>st(banned.begin(),banned.end());
        int maxi=0;
        int res=0;

        for(auto ele:mp){
if(ele.second>maxi and  !st.count(ele.first)){
    maxi=ele.second;
    res=ele.second;
}
        }
        return res;
    }
};