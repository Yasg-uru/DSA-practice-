class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      //  now we have approach to solve this question with the help of map
      vector<int>ans;
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++){
          mp[nums[i]]++;
      }
      for(auto ele:mp){
          if(ele.second>1){
              ans.push_back(ele.first);
          }
      }
      return ans;
    }
};