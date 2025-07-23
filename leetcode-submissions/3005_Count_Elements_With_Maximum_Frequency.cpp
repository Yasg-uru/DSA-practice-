class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int maxfreq=INT_MIN;
        unordered_map<int,int>mp;
        for(int ele:nums){
            mp[ele]++;
            maxfreq=max(maxfreq,mp[ele]);
        }
        int maxfreqcnt=0;
        for(auto ele:mp){
            if(maxfreq==ele.second){
                maxfreqcnt++;
            }
        }
     return maxfreq*maxfreqcnt;   
    }
};