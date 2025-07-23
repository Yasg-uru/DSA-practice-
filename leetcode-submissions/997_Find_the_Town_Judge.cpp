class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {
        //creating a hashmap to store the indegree of the particular node
        unordered_map<int,int>mp; 
        for(int i=0;i<trust.size();i++){
            mp[trust[i][0]]--;
            mp[trust[i][1]]++;


        }
        for(auto ele:mp){
            if(ele.second==n-1){
                return ele.first;
            }
        }
        return -1;
    }
};