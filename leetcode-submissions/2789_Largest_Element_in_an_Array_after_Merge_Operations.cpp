class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
       vector<long long>ans;
       for(int i=0;i<nums.size();i++){
           ans.push_back(nums[i]);
       }
       for(int i=nums.size()-1;i>0;i--){
           if(ans[i]>=ans[i-1]){
               ans[i-1]=ans[i]+ans[i-1];
           }
       } 
           int maxele=INT_MIN;
           for(int i=0;i<ans.size();i++){
              if(maxele<=ans[i]){
                  maxele=ans[i];
              }
           }
           return maxele;
    }
};