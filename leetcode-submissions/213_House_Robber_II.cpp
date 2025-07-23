class Solution {
public:
    int t[101];
    int solve(vector<int>&nums, int index, int n ){
        if(index>n){
            return 0;

        }
        if(t[index]!=-1) return t[index];
        int left = solve(nums, index+2,n)+nums[index];
        int right = solve(nums,index+1,n);
        return t[index]=max(left, right);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int from_0th_index = solve(nums, 0 ,nums.size()-2);
         memset(t,-1,sizeof(t));
        int from_1th_index= solve(nums, 1, nums.size()-1);
        return max(from_0th_index,from_1th_index);
    }
};