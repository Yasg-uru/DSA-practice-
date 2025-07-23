class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      vector<int>ans;
      unordered_map<int,int>mp;
      for(int i=0;i<nums2.size();i++){
        mp[nums2[i]]++;
      }
      set<int>s;
      for(int i=0;i<nums1.size();i++){
          if(mp.count(nums1[i])>0){
             s.insert(nums1[i]);
          }
      }
      
      
    for(int ele:s){
        ans.push_back(ele);
    }
    return ans;
    }
};