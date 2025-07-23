class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        queue<int>q;
        unordered_set<int>s(restricted.begin(), restricted.end());

        q.push(0 );
        vector<bool>visited(n, false);
        visited[0]= true;
        int processedNodes = 0;
        unordered_map<int , vector<int>>adj;
        for(auto& edge: edges){
            int  u = edge[0 ];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while(not q.empty()){
            int currNode = q.front();
            q.pop();
            processedNodes++;

            for(auto& nbr :adj[currNode] ){
                if(not s.count(nbr) and not visited[nbr]){
                    q.push(nbr);
                    visited[nbr]= true ;
                }
            }

        }
        return processedNodes;
    }
};