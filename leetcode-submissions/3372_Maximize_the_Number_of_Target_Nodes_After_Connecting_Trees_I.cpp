class Solution {
public:
    int bfs(unordered_map<int , vector<int>>&adj ,int currnode ,  int requiredDistance, int n ){
        queue<pair<int, int >>q;
        q.push({currnode, 0});
        vector<bool>visited(n , false);
        visited[currnode]= true ;
        int count =0;
        
        while(not q.empty()){
            auto [ currNode , currDistance ]= q.front();
            q.pop();
            if(currDistance>requiredDistance) continue;
             count++;
            for(auto& nbr : adj[currNode]){
                if(not visited[nbr]){
                    q.push({nbr , currDistance+1});
                    visited[nbr] = true ;
                    
                }
            }
        }
        return count ;
    }
    vector<int>findCount(vector<vector<int>>&edges , int k){
        int n = edges.size()+1;
        unordered_map<int , vector<int>>adj;
        for(auto& edge : edges){
            int u = edge[0];
            int v  = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>result(n, 0 );
        for(int i =0 ;i<n;i++){
            result[i] = bfs(adj , i  , k , n);
            
        }
        return result ;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int>result1 = findCount(edges1, k);
        vector<int>result2 = findCount(edges2, k-1);// assuming one edgde is already connected 
        int maxElement = *max_element(result2.begin(), result2.end());
        cout<<maxElement ;
        for(int i =0 ;i<result1.size();i++){
            result1[i]+=maxElement ;
        }
        return result1;

    }
};