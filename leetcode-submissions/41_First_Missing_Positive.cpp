class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //now solving this question by using the hashmap approach
        int maxnum=INT_MIN;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxnum=max(nums[i],maxnum);
        }
      for(int i=1;i<=maxnum;i++){
        if(mp.find(i)==mp.end()){
            return i;
        }

      }
      return maxnum+1;
    }
};