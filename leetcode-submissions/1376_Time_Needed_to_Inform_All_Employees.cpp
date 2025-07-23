class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int , vector<int>>adj;
        for(int i =0 ;i<manager.size();i++){
            if(manager[i]==-1){
                continue ;
            }
            adj[manager[i]].push_back(i);
        }
        queue<pair<int , int >>q;
        q.push({headID , 0 });
        int maxTime = 0 ;
        while(not q.empty()){
            auto [ currEmp , time ]  = q.front();
            q.pop();
            maxTime = (maxTime , time );
            for(int sub:adj[currEmp]){
                q.push({sub , time+informTime[currEmp]});
            }
        }
        return maxTime ;

    }
};