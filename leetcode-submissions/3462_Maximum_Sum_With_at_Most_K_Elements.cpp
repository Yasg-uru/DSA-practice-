class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long maxAns =0 ;
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int , int >>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push({grid[i][j], i});
            }
        }
        while(k--){
            auto [num, row]=pq.top();
            pq.pop();
            if(limits[row]>0){
                maxAns+=num;
                limits[row]--;
            }
        }
        return maxAns ;
        
    }
};