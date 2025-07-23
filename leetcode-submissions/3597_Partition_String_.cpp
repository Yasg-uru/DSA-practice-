class Solution {
public:
    vector<string> partitionString(string s) {
    unordered_set<string>isSeen;
        vector<string>ans;
        int n = s.length() ;
        string curr= "";
       for(int i =0;i<n;i++){
           curr+=s[i];
           if(not isSeen.count(curr)){
               ans.push_back(curr);
               isSeen.insert(curr);
               curr = "";
           }
       }
    return ans ;
    }
};