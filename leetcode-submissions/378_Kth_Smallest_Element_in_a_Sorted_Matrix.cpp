class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int count=0;
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                count++;
                
                if(count==k){
                    ans=matrix[i][j];
                    break;
                }
            }
        }
        return ans;
    }
};