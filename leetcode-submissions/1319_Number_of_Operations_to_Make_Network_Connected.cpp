class Solution {
public:
    vector<list<int>>graph;
   
    void dfs(int node,unordered_set<int>&visited){
        visited.insert(node);
        for(auto ele:graph[node]){
            if(not visited.count(ele)){
                
                dfs(ele,visited);
            }
        }
    }
    void add_edge(int u,int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
      //now we have an approach for solving this question is using bfs traversal technique and then finding the solution
       if(connections.size()<n-1){
           return -1;
       }
        graph.resize(n,list<int>());
        for(int i=0;i<connections.size();i++){
            add_edge(connections[i][0],connections[i][1]);
        }
        unordered_set<int>visited;
        int cnt=0;
      for(int i=0;i<n;i++){
          if(not visited.count(i)){
              visited.insert(i);
                cnt++;
              dfs(i,visited);
          }
      } 

        return cnt-1;
    }
};