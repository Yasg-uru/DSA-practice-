class Solution {
private: 
    bool dfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int source,int destination){
        visited[source]=true;
        if(source==destination){
            return true ;
        }
        bool isRecheable=false;
        for(auto &nbr:adj[source]){
           if(not visited[nbr]){
            isRecheable=isRecheable or  dfs(adj,visited,nbr,destination);
           }

        }
        return isRecheable;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<prerequisites.size();i++){
            int u =prerequisites[i][0];
            int v= prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<bool>ans;
        for(auto query :queries){
            int u =query[0];
            int v= query[1];
        vector<bool>visited(numCourses,false);
            if(dfs(adj,visited,u,v)){
                ans.push_back(true);
            }else {
                ans.push_back(false);
            }
        }
        return ans ;

    }
};