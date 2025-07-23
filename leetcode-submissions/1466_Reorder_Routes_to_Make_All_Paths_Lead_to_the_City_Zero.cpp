class Solution {
public:
    int result = 0 ;
    void DFS(unordered_map<int , vector<pair<int , int >>>&adj, int parent , int currNode){
        for(auto& nbr : adj[currNode]){
            
            int node = nbr.first ;
            int isOriginal = nbr.second;
            if(node==parent){
                continue;
            }
            if(isOriginal){
                result+=1;
            }
            DFS(adj , currNode , node);

        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
       unordered_map<int , vector<pair<int , int >>>adj ;
       for(auto& connection : connections){
        int u = connection[0];
        int v= connection[1];
        adj[u].push_back({v, 1});// one represents original edge
        adj[v].push_back({u , 0 });

       } 

       DFS(adj , -1, 0);
       return result ;

    }
};