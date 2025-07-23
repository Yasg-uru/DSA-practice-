class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++)
            {
                arr.push_back(grid[i][j]);
            }
        }
        int N = arr.size();

        int target = arr[N/2];
        int operations = 0;

        for(int& num : arr){
            if(target%x!=num%x){
                return -1;
            }
            operations+=abs(target-num)/x;
        }
        return operations ;
    }
};