class Solution {
private: 

    bool BFS(unordered_map<int,vector<int>>&adj,int source , int destination){
vector<bool>visited(n,false);
visited[source]=true ;
queue<int>q;
q.push(source);
while(not q.empty()){
    int currNode =q.front();
    q.pop();
    if(currNode==destination) return true ;
    for(auto& nbr:adj[currNode]){
        if(not visited[nbr]){
            q.push(nbr);

        }
    }
}
return false;
    }
public:
    int n ; 
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // we are solving this question by using the BFS traversal technique 
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<prerequisites.size();i++){
            int u =prerequisites[i][0];
            int v= prerequisites[i][1];
            adj[u].push_back(v);
        }
        n= numCourses;
        vector<bool>ans;
        for(auto& query: queries){
            int u =query[0];
            int v= query[1];
            if(BFS(adj,u,v)){
                ans.push_back(true);
            }else {
                ans.push_back(false);

            }
        }
        return ans ;

    }
};