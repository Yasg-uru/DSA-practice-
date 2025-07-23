class Solution {
public:
    void DFS(int currNode , unordered_map<int , vector<int>>&adj , vector<bool>&visited,int &vertices, int &NumberOfEdges ){
        visited[currNode]= true ;
        vertices+=1;
        NumberOfEdges+=adj[currNode].size();
        for(auto& nbr : adj[currNode]){
            if(not visited[nbr]){
                DFS(nbr , adj , visited,vertices,NumberOfEdges );
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n, false);
        unordered_map<int , vector<int>>adj ;
        for(auto& edge : edges){
            int u = edge[0];

            int v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int totalCompleteComponents = 0;

        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }
            int vertices = 0 ;
            int NumberOfEdges = 0;
            DFS(i , adj , visited, vertices , NumberOfEdges);
            int RequiredEdges = (vertices*(vertices-1))/2;
            NumberOfEdges/=2;
            if(RequiredEdges==NumberOfEdges){
                totalCompleteComponents++;
            }
        }
        return totalCompleteComponents;
    }
};