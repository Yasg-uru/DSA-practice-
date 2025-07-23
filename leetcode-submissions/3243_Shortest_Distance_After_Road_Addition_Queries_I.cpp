class Solution {
public:
    int bfs(int n,unordered_map<int,vector<int>>&adj){
        queue<int>q;
        q.push(0);
        vector<int>visited(n,false);
        visited[0]=true ;
        // now as we know we have fixed destination n-1 and we need t find out the shortest path so we need to return if we reaached at that element by any node first 
    int level=0;
        while(not q.empty()){
            int size=q.size();
            while(size--){
                int currNode=q.front();
                q.pop();
                if(currNode==n-1){
                    return level;
                }
                for(int neighbour:adj[currNode]){
                  if(not visited[neighbour]){
                      visited[neighbour]=true ;
                    q.push(neighbour);

                  }
                }
            }
            level++;

        }
        return -1;

    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>result;
        for(auto &query:queries){
            int u=query[0];
            int v=query[1];
            //after finding this we need to insert it in the adjacency list 
            adj[u].push_back(v);
            int d=bfs(n,adj);
            result.push_back(d);
        }
        return result ;
    }
};