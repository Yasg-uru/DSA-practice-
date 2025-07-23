class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
       if(nums.size()<k){
        return 0;
       }
       sort(nums.begin(),nums.end());
     
       int minans=nums[k-1]-nums[0];
       for(int i=k;i<nums.size();i++){
        minans=min(minans,nums[i]-nums[i-(k-1)]);
       }
       return minans;
    }
};