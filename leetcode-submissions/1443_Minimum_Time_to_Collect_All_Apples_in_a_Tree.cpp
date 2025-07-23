class Solution {
public:
    int DFS(int currNode , unordered_map<int , vector<int>>&adj , vector<bool>&hasApple, int parent){
        int time = 0; // initially time is 0 
        for(auto& nbr : adj[currNode]){
            if(nbr==parent)
            {
                continue;
            }
            int time_from_my_child = DFS(nbr , adj , hasApple, currNode);
            if(time_from_my_child>0 or hasApple[nbr]==true){
                time+=time_from_my_child+2;
            }
        }
        return time ;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       unordered_map<int , vector<int>>adj ;
       for(auto& edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);

       }
       return DFS(0 , adj , hasApple, -1);

    }
};