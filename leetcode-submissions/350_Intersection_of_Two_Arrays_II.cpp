class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
      unordered_map<int,int>mp;
      if(nums1.size()>nums2.size()){

      
      for(int i=0;i<nums1.size();i++){
          mp[nums1[i]]++;
      }  
      //NOW WE STORES THE FREQUENCY OF THE PARTICULAR ELEMENT
      for(int i=0;i<nums2.size();i++){
          if(mp.count(nums2[i])>0){
              ans.push_back(nums2[i]);
          }
      }
      }else{
          for(int i=0;i<nums2.size();i++){
          mp[nums2[i]]++;
      }  
      //NOW WE STORES THE FREQUENCY OF THE PARTICULAR ELEMENT
      for(int i=0;i<nums1.size();i++){
          if(mp.count(nums1[i])>0){
              ans.push_back(nums1[i]);
          }
      }
      }
      return ans;
    }
};