class Solution {
public:
     
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    unordered_map<int , vector<int >>adj ;
        

        
        for(int i=0;i<n;i++){
            for(int j= i+1;j<n;j++){
                if(abs(nums[i] - nums[j])<=maxDiff){
                   adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>ans ;
        for(auto& query : queries ){
            int u = query[0];
            int v = query[1];
            if(u==v){
                ans.push_back(0 );
            }
            bool isFound = false;
            queue<pair<int , int >>q;
            q.push({u ,0 });
            vector<bool>visited(n, false);
            visited[u] = true ;
            while(not q.empty()){
                int currNode = q.front().first;
                int currDistance = q.front().second ;
                if(currNode==v){
                    ans.push_back(currDistance);
                    isFound = true ;
                    break;
                }
                q.pop();
                for(auto& nbr : adj[currNode]){
                    if(not visited[nbr]){
                        q.push({nbr , currDistance+1});
                        visited[nbr] = true ;
                    }
                }
            }
            if(not isFound){
                ans.push_back(-1);
            }
        }
        return ans ;
    }
};