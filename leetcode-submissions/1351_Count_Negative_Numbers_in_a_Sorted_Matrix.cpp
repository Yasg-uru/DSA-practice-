class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0 ;
        for(vector<int>&vec:grid){
            for(int &n :vec){
                if(n<0){
                    cnt++;
                }
            }
        }
        return cnt ;
    }
};