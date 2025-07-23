class Solution {
public:
    typedef pair<int , pair<int , int >>P;
    vector<vector<int>>directions = { {0, 1}, {1, 0}, {-1, 0 }, {0 , -1}};

    int minimumEffortPath(vector<vector<int>>& h) {
        // this question is a proper implementation of the dijkstras algorithm 
        int m = h.size();
        int n = h[0].size();
        vector<vector<int>>result(m , vector<int>(n , INT_MAX));
        priority_queue<P, vector<P>, greater<P>>pq;
        result[0][0] = 0 ;
        pq.push({0 , {0, 0}});
        while(not pq.empty()){
            int dist = pq.top().first ;
            auto coord = pq.top().second ;
            pq.pop();
            int i = coord.first ;
            int j = coord.second ;
            for(auto& dir : directions ){
                int i_ = i+ dir[0];
                int j_ = j+ dir[1];
                // checking the bounds and then doing some operations here 
                if(i_>= 0 and j_>= 0 and i_<m and j_<n ){
                    int absDistance = abs(h[i][j]- h[i_][j_]);
                    int maxDistance = max(absDistance , dist);
                    if(maxDistance<result[i_][j_]){
                        pq.push({maxDistance , {i_, j_}});
                        result[i_][j_]= maxDistance;
                    }
                }
            }
        }
        return result[m-1][n-1];


    }
};