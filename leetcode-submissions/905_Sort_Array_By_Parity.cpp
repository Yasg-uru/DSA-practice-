class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
 
     int leftptr=0;
     int rightptr=nums.size()-1;
     while(leftptr<=rightptr){
         if(nums[leftptr]%2!=0 and nums[rightptr]%2==0){
             swap(nums[leftptr],nums[rightptr]);
             leftptr++;
             rightptr--;
         }else{
             leftptr++;
             rightptr--;
         }
     }  
     return nums; 
    }
};