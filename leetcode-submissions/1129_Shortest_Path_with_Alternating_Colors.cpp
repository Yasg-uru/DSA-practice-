class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    //  queue<int>q;
     vector<int>ans(n ,-1);
     unordered_map<int , vector<int>>red_adj , blue_adj;
     for(auto& edge : redEdges){
        int u = edge[0];
        int v  =edge[1];
        red_adj[u].push_back(v);
     }   
     for(auto& edge : blueEdges){
        int u  = edge[0];
        int v = edge[1];
        blue_adj[u].push_back(v);
     }
     
     queue<tuple<int , int , int >>q; // node , step , lastusedEdge(0 -> red, 1->blue) 
    vector<vector<bool>>visited(n , vector<bool>(2, false));
        q.push({0, 0 , 0 });
        q.push({0 , 0 , 1});
        visited[0][0]= visited[0][1]= true ;
        // visited[0][-1]
        while(not q.empty()){
            auto [currNode , currStep , lastUsedEdge]= q.front();
            q.pop();
            if(ans[currNode]==-1){
                ans[currNode]= currStep;
            }
            
            if(lastUsedEdge==0){
                // use blue edges 
                for(int&nbr : blue_adj[currNode]){
                    visited[nbr][0]= true ;
                    q.push({nbr , currStep+1, 1});
                }
            }else if(lastUsedEdge==1){
                //use red edges
                for(int& nbr : red_adj[currNode]){
                    visited[nbr][1]= true ;
                    q.push({nbr , currStep+1, 0});
                }

            }
        }
     return ans ;

    }
};