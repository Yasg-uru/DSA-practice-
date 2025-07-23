class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int count=0;
      int maxones=INT_MIN;
      for(int i=0;i<nums.size();i++){
          if(nums[i]==1){
              count++;
              maxones=max(maxones,count);
          }else{
              count=0;
          }
      }  
      return maxones;
    }
};