class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int left=0;
     int right=nums.size()-1;
     while(left<=right){
         if(nums[left]==0 and nums[right]!=0){
             swap(nums[left],nums[right]);
             left++;
             right--;

         }else{
             left++;
             right--;
         }
     } 
     
    }
};