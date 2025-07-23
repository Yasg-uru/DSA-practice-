class Solution {
public:
    int n ;
    vector<int>t;
    int solve(vector<int>&nums , int  &k , int i ){
        if(i>=n){
            return INT_MIN;
        }
        if(i==n-1){
            return nums[i];
        }
        if(t[i]!=INT_MIN){
            return t[i];
        }
        int maxAns  =INT_MIN ;
        for(int j =i+1;j<=min(i+k , n-1);j++){
            maxAns = max(maxAns , solve(nums , k , j));

        }
        return t[i]=  nums[i]+maxAns ;
    }
    int maxResult(vector<int>& nums, int k) {
        n = nums.size();
        t.resize(n , INT_MIN);
        return solve(nums , k , 0);

    }
};