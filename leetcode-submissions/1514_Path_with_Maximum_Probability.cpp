class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //this question is solved by using the depth first search strategy in which we need to check if the current situation is best or not if best then we need to store the probility of that 
        //now creating a graph fron the source to destination,succprb
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        //after this we need to traverse graph using BFS Traversal
        queue<pair<int,double>>q;
        q.push({start_node,1.0});
        vector<double>prob(n,0.0);
        prob[start_node]=1.0;
        while(not q.empty()){
            auto it=q.front();
            q.pop();
            for(auto neighbour:adj[it.first]){
                if(prob[neighbour.first]<(neighbour.second*it.second)){
                    prob[neighbour.first]=neighbour.second*it.second;

                q.push({neighbour.first,neighbour.second});
                }
            }
        }


return prob[end_node];
    }
};