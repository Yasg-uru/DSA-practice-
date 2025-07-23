class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup=0;
       for(int i=0;i<nums.size();i++){
           for(int j=i+1;j<nums.size();j++){
               if(nums[i]==nums[j]){
                   dup=nums[i];
                   break;
               }
           }
       } 
       return dup;
       
    }
};