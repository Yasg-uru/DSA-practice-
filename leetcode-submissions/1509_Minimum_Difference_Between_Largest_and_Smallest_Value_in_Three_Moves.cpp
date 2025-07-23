class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int answer=INT_MAX;
        int n=nums.size();

        answer=min(answer,nums[n-4]-nums[0]);
        answer=min(answer,nums[n-1]-nums[3]);
        answer=min(answer,nums[n-2]-nums[2]);
        answer=min(answer,nums[n-3]-nums[1]);
        return answer;
        
    }
};