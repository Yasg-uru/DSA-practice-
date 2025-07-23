class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res=0;
       //now we need to convert into string then sort it and compare their maximum digits
       for(int i=0;i<nums.size();i++){
           string first=to_string(nums[i]);
           sort(first.begin(),first.end());
           for(int j=i+1;j<nums.size();j++){
               string second=to_string(nums[j]);
               sort(second.begin(),second.end());
               if(first[first.size()-1]==second[second.size()-1]){
                   res=max(res,nums[i]+nums[j]);
               }
           }
       } 
       return res==0?-1:res;
    }
};