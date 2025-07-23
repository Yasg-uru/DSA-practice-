
class Solution {
public: 
    void DFS(unordered_map<int, vector<int>>&adj , unordered_set<int>&visited, int currNode){
        visited.insert(currNode);
        for(auto& nbr :adj[currNode]){
            if(visited.find(nbr)==visited.end()){
                DFS(adj , visited, nbr);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
       unordered_map<int , vector<int>>adj ;
       int n = bombs.size();
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;

            }
            long long  x1 = bombs[i][0];
            long long  y1 = bombs[i][1];
            int r1 = bombs[i][2];

            long long  x2 = bombs[j][0];
            long long  y2 = bombs[j][1];
            long long  r2 = bombs[j][2];
            int distance = sqrt((pow(x2-x1, 2), pow(y2-y1, 2)));
            if(r1>=distance){
                adj[i].push_back(j);
            }

        }

       } 
       int maxAns= 1 ;

       unordered_set<int>visited;
       for(int i=0;i<n;i++){
        visited.clear();

        DFS(adj , visited, i );
        int detonatedBombsCount = visited.size();
        maxAns = max(maxAns ,detonatedBombsCount );

       }
       return maxAns ;
    }
};