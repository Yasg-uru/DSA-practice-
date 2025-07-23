class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
       int n = arr1.size(), maxAns =0 ;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<n;j++){
                maxAns = max(maxAns ,abs(arr1[i]-arr1[j])+abs(arr2[i]-arr2[j])+abs(i-j) );
            }
        }
        return maxAns ;
    }
};