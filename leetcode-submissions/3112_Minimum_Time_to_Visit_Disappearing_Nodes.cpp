class Solution {
public:
    typedef pair<int , pair<int ,int >>P;

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0 , {0 , 0}});
        vector<int>dist(n , INT_MAX);
        dist[0]= 0;
        unordered_map<int , vector<pair<int , int >>>adj;
        for(auto& edge : edges){
            int u = edge[0 ];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u , wt});
        }
        while(not pq.empty()){
            int currNode = pq.top().second.first ;
            int currTime = pq.top().second.second ;
            int currWt = pq.top().first ;
            pq.pop();
            for(auto&nbr : adj[currNode]){
                if(currTime+1>=disappear[nbr.first]){
                    continue;
                }
                if(currWt+nbr.second<dist[nbr.first]){
                    pq.push({currWt+nbr.second, {nbr.first, currTime+1}});
                    dist[nbr.first]= currWt+nbr.second;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
};