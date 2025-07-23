class Solution {
public:
    void bfs(unordered_set<int>&visited , int src , unordered_map<int , vector<int>>&adj , vector<int>&ans ){
       
           queue<int>q;
       q.push(src);
        visited.insert(src);
       
        int currColor = 1;
        while(not q.empty()){
            int currNode = q.front();
            q.pop();
            ans.push_back(currColor);
            currColor++;
            for(int& nbr : adj[currNode]){
                if(not visited.count(nbr)){
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
        }
       
        
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int , vector<int>>adj;
          unordered_set<int>visited;
    
        for(auto& path : paths){
            int u = path[0];
            int v = path[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
         vector<int>ans ;
        for(int i =1;i<=n;i++){
            if(not visited.count(i)){
                bfs(visited , i , adj , ans );
            }
        }
        return ans ;
    }
};