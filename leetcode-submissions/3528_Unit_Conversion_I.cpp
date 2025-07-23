class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int MOD = 1e9+7;
        unordered_map<int , vector<pair<int , int >>>adj;
        for(auto& conversion : conversions){
            int u = conversion[0];
            int v= conversion[1];
            int factor = conversion[2];
            adj[u].push_back({v, factor});
            
        }
        int n = conversions.size()+1;
        vector<int>baseConversion(n , -1 );
        baseConversion[0 ] = 1;
        queue<int>q;
        q.push(0);
        while(not q.empty()){
            int currNode = q.front();
            q.pop();
            for(auto& nbr : adj[currNode]){
                int f = nbr.second ;
                int nbrNode = nbr.first;
                long long newUnit = (1LL * baseConversion[currNode] * f) % MOD; 
                baseConversion[nbrNode] = newUnit;
                q.push(nbrNode);
            }
        }
        return baseConversion;
    }
};