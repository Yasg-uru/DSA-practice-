class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>rank(n, 0 );
        vector<vector<bool>>isConnected(n ,vector<bool>(n, false));

        for(auto& road:roads){
            int u = road[0];
            int v = road[1];
            rank[u]++;
            rank[v]++;
            isConnected[u][v]= true;


        }
        int maxRank = 0 ;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            int totalRank = rank[i]+rank[j];
            if(isConnected[i][j]==true){
                totalRank-=1;
            }
            maxRank= max(maxRank , totalRank);
            }   
        }
        return maxRank;
    }
};