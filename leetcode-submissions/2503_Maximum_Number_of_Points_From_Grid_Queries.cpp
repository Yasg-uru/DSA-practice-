class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int, int >>Queries;
        int Q = queries.size();
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<Q;i++){
            Queries.push_back({queries[i], i});
        }
        sort(begin(Queries), end(Queries));
        priority_queue<pair<int , pair<int, int>>, vector<pair<int , pair<int, int>>>, greater<pair<int , pair<int, int>>>>pq;
        pq.push({grid[0][0], {0 , 0}});
        int points =0;
        vector<vector<bool>>visited(m , vector<bool>(n , false));
        vector<int>ans(Q, 0);

        visited[0][0]= true ;
        vector<vector<int>>directions = { { 0 , 1} , {1, 0}, {0 ,-1}, {-1, 0}};
        for(int i=0;i<Q;i++){
            int queryVal= Queries[i].first;
            int index = Queries[i].second;
            while(not pq.empty() and pq.top().first<queryVal){
                int currVal = pq.top().first;
                int i = pq.top().second.first;
                int j = pq.top().second.second;
                points++;
                pq.pop();
                for(auto& dir : directions){
                    int i_ = i+dir[0];
                    int j_ = j+dir[1];
                    if(i_>=0 and j_>=0 and i_<m and j_<n and not visited[i_][j_]){
                        pq.push({grid[i_][j_], {i_, j_}});
                        visited[i_][j_]= true;
                    }
                }
            }
            ans[index] = points;
        }
    return ans ;
    }
};