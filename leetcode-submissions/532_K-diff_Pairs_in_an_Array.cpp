class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
     
      set<pair<int,int>>st;
      //sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
               if(abs(nums[i]-nums[j])==k and i!=j){
                   st.insert({nums[i],nums[j]});
               }
            }
        }
        return st.size();
    }
};