class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int count =0;
        int n=nums.size();
        double ans=0;

        sort(nums.begin(),nums.end());
        int left=0,right=n-1;
        while(count<(n/2)){
            count++;
            ans+=(double)(nums[left]+nums[right])/2;
            left++;
            right--;

        }
        return ans;
    }
};