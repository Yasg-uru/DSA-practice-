class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      vector<int>ans;
      unordered_map<int,int>nextgreater;
      stack<int>st;
      for(int i=nums2.size()-1;i>=0;i--){
          while(!st.empty() and st.top()<nums2[i]){
              st.pop();
          }
          if(st.empty()){
              nextgreater[nums2[i]]=-1;
          }else{
              nextgreater[nums2[i]]=st.top();
          }
          st.push(nums2[i]);
      }  
      for(int nums:nums1){
          ans.push_back(nextgreater[nums]);
      }
      return ans;

    }
};