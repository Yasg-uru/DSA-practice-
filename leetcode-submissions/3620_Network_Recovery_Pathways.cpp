class Solution {
public:
    typedef pair<int , int >P;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        if(!online[0] or !online[n-1]){
            return -1;
        }
        
        unordered_map<int , vector<P>>adj;
        for(auto& ed:edges){
            adj[ed[0]].push_back({ed[1], ed[2]});
            adj[ed[1]].push_back({ed[0], ed[2]});
        }

        priority_queue<pair< long long , int >, vector<pair<long long , int >>, greater<pair<long long , int >>>maxHeap;
        maxHeap.push({ 0 , 0});
        vector<long long >c(n , LLONG_MAX);
        c[0]= 0 ;
        int result = -1;
        while(not maxHeap.empty()){
            auto [  TCost , currNode] = maxHeap.top();
            maxHeap.pop();
            if(TCost>c[currNode]){
                continue ;
            }
            if(currNode == n-1){
                return TCost;
            }
            for(auto& nbr : adj[currNode]){
                if(not online[nbr.first] || nbr.second>k){
                    continue ;
                }
               long long newPath = max(TCost , (long long )nbr.second);
                if(newPath <c[nbr.first]){
                    c[nbr.first] = newPath;
                    maxHeap.push({newPath , nbr.first});
                }
            }
        }
        return -1 ;
    }
};