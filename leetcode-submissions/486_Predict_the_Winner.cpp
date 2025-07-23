class Solution {
public:
    int solve(int  i , int j , vector<int>&nums){
        if(i>j)return 0 ;
        if(nums[i]==nums[j]) return nums[i];
        int take_i= nums[i]+min(solve(i+2, j, nums), solve(i+1, j-1, nums));
        int take_j= nums[j]+min(solve(i, j-2, nums), solve(i+1, j-1, nums));
        return max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int totalScore = accumulate(begin(nums), end(nums), 0 );
        int n = nums.size();
        int player_1_score = solve(0 , n-1, nums);
        int player_2_score = totalScore - player_1_score;
        return player_1_score>= player_2_score;
    }
};