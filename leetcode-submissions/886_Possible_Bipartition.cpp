class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // this question belongs to the bipartite concept so just we need to use the exact same template to solve this question 
         queue<int>q;
         unordered_map<int, vector<int>>adj ;
         vector<int>colors(n+1, -1);
         for(auto& relation : dislikes){
            int u = relation[0];
            int v = relation[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
         }
         q.push(1);
         colors[1]= 0 ;// red 

         while(not q.empty()){
            int currNode = q.front();
            q.pop();
            for(auto& nbr : adj[currNode]){
                if(colors[nbr]==colors[currNode]){
                    return false;// same color found
                }else if(colors[nbr]==-1){
                    colors[nbr]= (colors[currNode]==0)?1:0;
                    q.push(nbr);

                }
            }
         }
         return true ;
    }
};