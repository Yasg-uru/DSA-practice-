class Solution {
public:
    int n ;
    vector<vector<int>>t;
    int solve(vector<int>&nums, int k , int i ){
       if(k==0){
        return 0;

       }
       if(i>=n){
        return INT_MAX;
       }
       if(t[i][k]!=-1){
        return t[i][k];
       }
       int take = max(nums[i], solve(nums , k-1,i+2));
       int skip = solve(nums , k, i+1);
       return t[i][k]= min(take , skip);
    }
    int minCapability(vector<int>& nums, int k) {
        n= nums.size();
        t.assign(n + 1, vector<int>(k + 1, -1));
        return solve(nums , k , 0 );

    }
};