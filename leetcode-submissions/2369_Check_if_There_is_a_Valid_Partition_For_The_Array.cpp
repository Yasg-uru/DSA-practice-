class Solution {
public:
    int n ;
    int t[100001];
    int solve(vector<int>&nums , int i ){
        if(i>=n) return true ;
        if(t[i]!=-1) return t[i];
        bool res= false;
        if(i+1<n and nums[i]==nums[i+1]){
            res= solve(nums, i+2);
            if(res) return true ;
        }
        if(i+2<n and nums[i]==nums[i+1] and nums[i+1]==nums[i+2]){
            res= solve(nums , i+3);
            if(res) return true ;
        }
        if(i+2<n and nums[i+1]-nums[i]==1 and nums[i+2]-nums[i+1]==1){
            res= solve(nums , i+3);
            if(res) return true ;
        }
        return t[i]=res;
    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        memset(t, -1 , sizeof(t));
        return solve(nums , 0 );
        
    }
};