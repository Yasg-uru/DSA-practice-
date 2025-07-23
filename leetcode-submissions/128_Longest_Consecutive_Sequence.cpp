class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int currLength = 1;
        int maxLength = 0 ;
         for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) continue ;
            if((nums[i]+1)==nums[i+1]){
                currLength++;
            }else {
                maxLength = max(maxLength , currLength);
                currLength= 1;
            }
         }
         return max(maxLength , currLength);
    }
};