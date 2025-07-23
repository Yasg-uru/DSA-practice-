class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       long long  perimeter =0 ;
       long long  remainingSum = 0 ;
       long long  n = nums.size();
       for(int i=0;i<n;i++){
        if(nums[i]<remainingSum){
            perimeter  = remainingSum+nums[i];
        }
        remainingSum+=nums[i];
       } 
       return perimeter==0?-1:perimeter;
    }
};