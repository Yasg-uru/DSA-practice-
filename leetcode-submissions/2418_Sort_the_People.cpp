class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string>mp;
        for(int i=0;i<names.size();i++){
            mp[heights[i]]=names[i];
        }
        vector<string>ans;

        for(auto ele:mp){
            ans.push_back(ele.second);


        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};