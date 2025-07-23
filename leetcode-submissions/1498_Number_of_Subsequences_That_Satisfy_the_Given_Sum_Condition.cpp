class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>powers(n );
        powers[0]= 1;
        for(int i =1;i<n;i++){
            powers[i]= powers[i-1]*2;
        }
        int left =0 , right =n-1, ans =0 ;
        sort(nums.begin(), nums.end());
        while(left<=right){
            if((nums[left]+nums[right])<=target){
                ans+=powers[(right-left)];
                left++;
            }else{
                right--;
            }
        }
        return ans ;
    }
};