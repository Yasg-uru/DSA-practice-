class Solution {
public:
    typedef pair<int , int > P;
    int countPaths(int n, vector<vector<int>>& roads) {
     priority_queue< P, vector<P>, greater<P>>pq;
     vector<int>result(n , INT_MAX);
     result[0]= 0 ;
     pq.push({0,0});
     int pathCounts = 0 ;
    unordered_map<int , vector<P>>adj;
    for(auto& road : roads){
        int u = road[0];
        int v= road[1];
        int time  = road[2];
        adj[u].push_back({v, time});
        adj[v].push_back({u , time});
    }
     while(not pq.empty()){
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto& nbr :adj[node]){
            int newTime = nbr.second ;
            int nbrNode = nbr.first;
            int totalTime = newTime+time;
            if(totalTime<=result[nbrNode]){
                pq.push({totalTime , nbrNode});
                result[nbrNode]= totalTime;
                if(nbrNode==n-1){
                    pathCounts++;
                }
            }
        }
     }  
     return pathCounts;
    }
};