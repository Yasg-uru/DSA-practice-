class Solution {
public:
    int t[100000][2];
    long long solve(vector<int>nums, int index,bool isAddition=true ){
        if(index>=nums.size()) return 0;
        if(t[index][isAddition]!=-1) return t[index][isAddition];
        long long val= nums[index];

        if(not isAddition){
            val=-val;
        }
        long long take =val+solve(nums,index+1,!isAddition);
        long long not_take =solve(nums ,index+1,isAddition);
        return t[index][isAddition]=max(take,not_take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,true);
    }
};