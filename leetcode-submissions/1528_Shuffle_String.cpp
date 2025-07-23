class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        unordered_multimap<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp.insert(make_pair(s[i],indices[i]));

        }
        vector<char>temp(s.size());
        for(auto ele:mp){
            temp[ele.second]=ele.first;
        }

        string ans(temp.begin(),temp.end());\
        return ans;

    }
};