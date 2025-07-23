class Solution {
public:
    int n ;
    bool checkWithDiffArray(vector<int>&nums, vector<vector<int>>& queries, int k ){
         vector<int>diffArray(n , 0 );
        for(int i=0;i<=k;i++){
            vector<int>query= queries[i];
            int u = query[0];
            int v = query[1];
            int val= query[2];
            diffArray[u]+=val;
            if(v+1<n){
                diffArray[v+1]-=val;
            }
        }
       int cumSum = 0 ;
        for(int i=0;i<n;i++){
            cumSum+=diffArray[i];
            diffArray[i]= cumSum;
            
           if(nums[i]-diffArray[i]>0){
            return false;
           }
        }
       
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         n = nums.size();
       
        int k = queries.size();
        for(int i=0;i<k;i++){
            if(checkWithDiffArray(nums, queries, i )==true){
                return i+1;
            }
        }
        return - 1;

    }
};