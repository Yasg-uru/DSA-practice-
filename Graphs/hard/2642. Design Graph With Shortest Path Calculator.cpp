#include <bits/stdc++.h>
using namespace std;
class Graph {
    public:
        unordered_map<int , vector<pair<int , int >>>adj;
        int N ;
    
        Graph(int n, vector<vector<int>>& edges) {
            N= n;
            for(int i=0;i<edges.size();i++){
                int u = edges[i][0];
                int v= edges[i][1];
                int wt = edges[i][2];
                adj[u].push_back({v, wt});
                
    
            }
        }
        
        void addEdge(vector<int> edge) {
             int u = edge[0];
                int v= edge[1];
                int wt = edge[2];
                adj[u].push_back({v, wt});
                
        }
        
        int shortestPath(int src, int dest) {
            vector<int>result(N , INT_MAX);
            result[src]= 0 ;
            priority_queue<pair<int , int >, vector<pair<int  , int>>, greater<pair<int , int >>>pq;
            pq.push({0 , src});
            while(not pq.empty()){
                int node = pq.top().second ;
                int currWt = pq.top().first;
                pq.pop();
                for(auto& nbr : adj[node]){
                    int totalTime = nbr.second+currWt;
                    int nbrNode = nbr.first;
                    if(totalTime<result[nbrNode]){
                        result[nbrNode] = totalTime;
                        pq.push({totalTime , nbrNode});
                    }
                }
            }
            return result[dest]==INT_MAX?-1:result[dest];
        }
    };
    
    /**
     * Your Graph object will be instantiated and called as such:
     * Graph* obj = new Graph(n, edges);
     * obj->addEdge(edge);
     * int param_2 = obj->shortestPath(node1,node2);
     */