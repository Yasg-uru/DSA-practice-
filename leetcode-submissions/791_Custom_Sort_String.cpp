class Solution {
public:
    string customSortString(string order, string s) {
        //now we have approach to solve this question 
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;

        }
        string ans="";
        for(int i=0;i<order.size();i++){
            if(mp.find(order[i])!=mp.end()){
                ans.push_back(order[i]);
                mp.erase(order[i]);
            }
        }
        for(auto ele:mp){
            ans.push_back(ele.first);

        }
        return ans;
    }
};