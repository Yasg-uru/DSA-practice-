class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int , int >mp;
        int n = grid.size();
        for(int  i=1;i<=n*n;i++){
            mp[i]= 0 ;
        }
        for(int i=0;i<n;i++ ){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
      int twice= 0 ;
      int missing = 0 ;

        for(auto& [num , freq]: mp){
            if(freq==0){
                missing= num;
            }
            if(freq==2){
                twice= num;
            }
        }
        return {twice, missing};
    }
};