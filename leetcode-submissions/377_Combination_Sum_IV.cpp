class Solution {
public:
    int n ;
    int t[201][1001];

    int solve(int i , vector<int>& nums, int target){
        if(target==0){
            return 1;

        }
        if(target<0 or i>=n){
            return 0 ;
        }
        if(t[i][target]!=-1){
            return t[i][target];
        }
        int take = solve(0 , nums , target-nums[i]);
        int not_take= solve(i+1, nums , target);
        return t[i][target]=  take+not_take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n= nums.size();
        memset(t, -1, sizeof(t));
        return solve(0 , nums ,target);
    }
};