class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        queue<int>q;
        for(int u=0;u<n;u++){
            for(int v:graph[u]){
                adj[v].push_back(u);
                indegree[u]++;

            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans ;
        while(not q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(int nbr:adj[curr]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);

                }
            }
            
        }
        sort(ans.begin(),ans.end());
    return ans;
    }
};