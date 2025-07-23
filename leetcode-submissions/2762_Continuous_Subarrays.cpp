class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
    long long ans=0;
    int left=0;
    int right=0;
    map<int,int>mp;

    while(right<nums.size()){
        mp[nums[right]]++;
        right++;
        while(mp.rbegin()->first-mp.begin()->first>2){
            mp[nums[left]]--;
            if(mp[nums[left]]==0) mp.erase(nums[left]);
            left++;
        }
        ans+=right-left;
    }
    return ans ;
    }
};