class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        int i=0;
vector<string>ans;
  while(i<n){
      int start=i;
      int end=i;
      while(end+1<n and nums[end+1]==nums[end]+1){
          end++;
      }
      if(end>start){
          ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));

      }else{
          ans.push_back(to_string(nums[start]));
      }
      i=end+1;
  }
  return ans;

    }
};