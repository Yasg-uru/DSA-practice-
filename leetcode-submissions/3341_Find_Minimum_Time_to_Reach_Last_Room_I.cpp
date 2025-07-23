class Solution {
public: 
    typedef pair<int , pair<int , int > >P;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0 , {0 , 0} }) ;
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>>distance(m , vector<int>(n , INT_MAX));
        distance[0][0] = 0 ;
        vector<vector<int>>directions = {{0 , 1}, {1, 0 }, {0 , -1}, {-1, 0}};
        while(not pq.empty()){
            int i = pq.top().second.first;
            int j = pq.top().second.second ;
            int currTime = pq.top().first ;
            pq.pop();
            for(auto& dir : directions ){
                int i_ = dir[0]+i ;
                int j_ = dir[1]+j;
                if(i_>=0 and j_>=0 and i_<m and j_<n){
                    int totalTime = currTime+moveTime[i_][j_]+1;
                    if(distance[i_][j_]>totalTime){
                        distance[i_][j_] = totalTime ;
                        pq.push({totalTime , {i_, j_}});

                    }
                }
            }
        }   
        return distance[m-1][n-1]-moveTime[m-1][n-1];

    }
};