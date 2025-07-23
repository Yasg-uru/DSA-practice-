class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        //now first we need to create vector with pair for storing particular index with value
        vector<int>result(nums1.size(),-1);
        vector<pair<int,int>>sortnums;
        queue<int>remaining;
        for(int i=0;i<nums2.size();i++){
            sortnums.emplace_back(nums2[i],i);
        }
        sort(sortnums.begin(),sortnums.end());
        for(int nums:nums1){
            if(nums>sortnums[0].first){
                result[sortnums[0].second]=nums;
                sortnums.erase(sortnums.begin());

            }else{
                remaining.push(nums);
            }
        }
   for(int i=0;i<result.size();i++){
       if(result[i]==-1){
           result[i]=remaining.front();
           remaining.pop();
       }
   }
   return result;
    }
};