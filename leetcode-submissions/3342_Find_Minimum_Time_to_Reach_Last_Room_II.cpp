class Solution {
public:
     typedef pair<int , vector<int > >P;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<P , vector<P>, greater<P>>pq;
        vector<vector<int>>directions = {{ 0, 1}, {1, 0 }, { -1 , 0 }, { 0 , -1}};
        pq.push({0 , {0 , 0 , 0}});
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>>result(m , vector<int>( n , INT_MAX));
        result[0][0] = 0 ;
        while(not pq.empty()){
            int currentTime = pq.top().first;
            int  i = pq.top().second[0];
            int j = pq.top().second[1];
            int isSingleMove = pq.top().second[2];

            pq.pop();
            for(auto& dir : directions ){
                int i_ = dir[0]+i ;
                int j_ = dir[1]+j;
                if(i_>=0 and j_>=0 and i_<m and j_<n ){
                    int minTime = max(currentTime , moveTime[i_][j_])+(isSingleMove==1?1:2);
                    if(result[i_][j_]>minTime){
                        result[i_][j_] = minTime ;
                        pq.push({minTime , {i_ , j_, !isSingleMove}});

                    }
                }
            }
        }
        if(result[m-1][n-1]==INT_MAX){
            return -1;
        }
        return result[m-1][n-1];
    }
};