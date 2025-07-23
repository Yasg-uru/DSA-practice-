class Solution {
public:
    int n ;
    int solve(vector<int>&nums , int i , int prev ){
       if(i>=n){
           return 0 ;
           
       }
        int picked = 0 ,  not_picked=0;
        if(prev==-1 or nums[i]>prev){
            picked= 1+solve(nums , i+1, nums[i]);
            
        }else{
            not_picked= solve(nums , i+1, prev);
        }
            
        
        return max(picked , not_picked);
    }
    int findLengthOfLCIS(vector<int>& nums) {
         n = nums.size();
        int maxLength = 1;
        int currLength =1;
        for(int i =1 ;i<n;i++){
            if(nums[i-1]<nums[i]){
                currLength++;
                
                maxLength = max(maxLength , currLength);
            }else{
                currLength= 1;
            }
        }
        return maxLength ;
    }
};