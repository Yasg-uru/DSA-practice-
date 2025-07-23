class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
     int start=0;
     int end=0;
     int cnt=INT_MIN;
     for(;end<nums.size();end++){
        mp[nums[end]]++;
        while(mp[nums[end]]>k){
            mp[nums[start++]]--;
        }
        cnt=max(cnt,end-start+1);

     }
return cnt;
    }
};