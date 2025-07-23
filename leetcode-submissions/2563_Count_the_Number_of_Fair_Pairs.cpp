class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(lower<=(nums[i]+nums[j]) and (nums[i]+nums[j])<=upper){
                    ans++;
                }
            }
        }
        return ans;
    }
};