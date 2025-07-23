class Solution {
public:
    int t[2502][2502];
    int solve(vector<int>nums , int index , int prevIndex){
        if(index>=nums.size()) return 0 ;
        int take =0;
        if(p!=-1 and t[index][prevIndex]!=-1) return t[index][prevIndex];
        if(prevIndex==-1 or nums[prevIndex]<nums[index]){
            take= 1+solve(nums, index+1, index);
        }
        int not_take =solve(nums, index+1,prevIndex);
        return t[index][prevIndex]=max(take,not_take);


    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums , 0,-1);
    }
};