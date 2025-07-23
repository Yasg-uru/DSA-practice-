class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        if(n==0){
            return 0 ;
        }
        unordered_map<int , vector<int>>adj;
        for(auto& edge:edges){
            int u = edge[0];
            int v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
                
        }
        vector<vector<int>>distance(n , vector<int>(n , 0));
        queue<pair<int , int >>q;
        int maxLength = 1 ;
         for(int i =0 ;i<n;i++){
             q.push({i , i});
             distance[i][i] = 1;
         }
        for(auto& edge : edges){
            int u = edge[0];
            int v= edge[1];
            if(label[u]==label[v]){
                if(distance[u][v]==0){
                    q.push({u , v});
                    distance[u][v]= 2;
                    distance[v][u]= 2;
                    maxLength = max(maxLength , 2);
                }
            }
        }
        while(not q.empty() ){
            auto [ u , v]= q.front();
            q.pop();
            int currLength = distance[u][v];
            for(int u_:adj[u]){
                for(int v_ : adj[v]){
                    if(label[u_] == label[v_] and distance[u_][v_]==0){
                        int newLength = currLength+2;
                        distance[u_][v_]= distance[v_][u_]= newLength;
                        q.push({u_, v_});
                        maxLength = max(maxLength , newLength);
                    }
                }
            }
        }
        return maxLength ;
    }
};