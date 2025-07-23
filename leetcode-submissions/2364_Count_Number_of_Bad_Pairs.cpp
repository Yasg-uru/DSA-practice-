class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       unordered_map<int,int>mp;
       int totalPairs=0;
       mp[nums[0]]=1;
       for(int j=1;j<nums.size();j++){
        int totalNumsBeforeJ= j;
        int badPairs = totalNumsBeforeJ-mp[nums[j]-j];
        mp[nums[j]-j]++;
        totalPairs+=badPairs;
       }
       return totalPairs;
    }
};