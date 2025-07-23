class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        set<int>sp(spaces.begin(),spaces.end());
        string ans="";
        int last_index=0;

        for(int i=0;i<s.size();i++){
            if(sp.count(i)){
                ans+=s.substr(last_index,i-last_index);
                ans+=" ";
                last_index=i;
            }
        }
        ans+=s.substr(last_index,s.size()-last_index);
        return ans;
    }
};