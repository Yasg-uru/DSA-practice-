class Solution {
public:
int subarrayatmostk(vector<int>&nums,int k){
    unordered_map<int,int>mp;
       int left=0;
       int ans=0;
       int right=0;
       while(right<nums.size()){
        mp[nums[right]]++;
        while(mp.size()>k){
            mp[nums[left]]--;
            if(mp[nums[left]]==0){
                mp.erase(nums[left]);
            }
            left++;
        }
        ans+=(right-left+1);
        right++;
       }

return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return (subarrayatmostk(nums,k)-subarrayatmostk(nums,k-1));
    }
};