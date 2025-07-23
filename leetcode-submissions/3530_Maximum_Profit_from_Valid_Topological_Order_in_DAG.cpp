class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        sort(score.begin(), score.end());
        int p = 1;
        vector<int>indegree(n , 0 );
         unordered_map<int , vector<int> > adj ;
        queue<int > q;
        int ans =0 ;
        
        for(auto& edge : edges ){
            int u = edge[0];
            int  v= edge[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        for(int i =0 ;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(not q.empty()){
            int currNode = q.front();
            q.pop();
            ans+= (score[currNode] *p);
            p++;
            for(auto& nbr : adj[currNode]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                    
                }
            }
            
        }
        return ans ;
    }
};