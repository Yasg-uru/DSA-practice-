class Solution {
public:
    // as code story with mik explained that parent will remain same if the currentNode and power is same because we are on the same level 
    int t[100001][14];

    int dfs(vector<int>&coins , int currNode , int parent , int& k ,unordered_map<int, vector<int>>&adj, int p){
        if(p>=14){
            return 0 ;
            //because if poweer is too large then also it calculates zero answer 

        }
        if(t[currNode][p]!=-1){
            return t[currNode][p];
        }
        int case1 = (coins[currNode]/pow(2,p))-k;
        int case2 = coins[currNode]/pow(2,p+1);
        for(auto& nbr:adj[currNode]){
            if(nbr!=parent){
                case1+=dfs(coins, nbr, currNode , k ,adj, p);
                case2+=dfs(coins, nbr, currNode , k ,adj, p+1);
            }
        }
        return t[currNode][p]= max(case1, case2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        unordered_map<int, vector<int>>adj ;
        memset(t, -1 ,sizeof(t));
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(coins , 0 , -1, k, adj, 0 );

    }
};