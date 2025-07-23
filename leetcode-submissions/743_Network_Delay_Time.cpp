class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int >>>adj ;
        priority_queue<pair<int, int > , vector<pair<int, int >>, greater<pair<int, int >>>pq;
        vector<int>result(n+1, INT_MAX);
        for(auto& vec : times){
            int u = vec[0];
            int v= vec[1];
            int time = vec[2];
            adj[u].push_back({v, time});
            // adj[v].push_back({u , time});
        }
        result[k]= 0 ;
        pq.push({0 , k});
        while(not pq.empty()){
            auto [ currDistance , currNode ]= pq.top();
            pq.pop();
            for(auto& nbr : adj[currNode]){
                int adjNode = nbr.first;
                int adjWt = nbr.second ;
                if(currDistance+adjWt<result[adjNode]){
                    result[adjNode]= currDistance+adjWt;
                    pq.push({currDistance+adjWt, adjNode});

                }
            }
        }
        int ans =  INT_MIN ;
        for(int i=1;i<=n;i++){
            
                ans = max(ans, result[i]);
            

        }
        return (ans==INT_MAX)?-1:ans;

    }
};