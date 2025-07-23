class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        deque<int>q;
        int m  = grid.size(), n = grid[0].size();
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<n;j++){
                q.push_back(grid[i][j]);
            }
        }
        while(k--){
            int front= q.back();
            q.pop_back();
            q.push_front(front);
        }
        vector<vector<int>>ans(m , vector<int>(n, 0));
        for(int i =0 ;i<m;i++){
            for(int j =0 ;j<n;j++){
                int front = q.front();
                ans[i][j]= front;
                q.pop_front();
            }
        }
        return ans ;
    }
};