class Solution {
public:
    int n;
    vector<list<int>>Graph;
    void add_edge(int u,int v){
        Graph[u].push_back(v);
    }
    vector<vector<int>>ans;
    void dfs(int node ,vector<int>&path,int target){
        
        path.push_back(node);


    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        Graph.resize(n,list<int>());
        for(int i=0;i<n;i++){
           for(int j=0;j<graph[0].size();j++){
               add_edge(i,graph[i][j]);
           }
        }
        vector<int>path;
        topologicalbfs(0,path,n-1);
return ans;
    }
};