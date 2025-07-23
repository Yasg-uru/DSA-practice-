class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int , unordered_set<int>>usersUAM;

        for(auto& log : logs){
            int user = log[0];
            int minute = log[1];
            usersUAM[user].insert(minute);
        }
        unordered_map<int , int>SameUAMUsers;
        for(auto& ele : usersUAM){
            int uam = ele.second.size() ;
            int user = ele.first ;
            SameUAMUsers[uam]++;
        }
        vector<int>ans(k);
        for(auto& ele:SameUAMUsers){
            int uam = ele.first;
            int users = ele.second ;
            if(uam<=k){
                ans[uam-1] = users;
            }

        }
        return ans ;
    }
};