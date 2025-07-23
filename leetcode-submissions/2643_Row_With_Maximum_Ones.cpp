class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxones=INT_MIN;
        int maxonesrow=INT_MIN;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int numberofones=0;
                if(mat[i][j]==1){
                    numberofones++;
                }
                if(numberofones>maxones){
                    maxones=numberofones;
                    maxonesrow=i;
                    break;
                }
            }
        }
        vector<int>ans={maxonesrow,maxones};
        
    }
};