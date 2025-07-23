class Solution {
public:

    int findMaxK(vector<int>& nums) {
      unordered_set<int>s;
      int maxele=-1;
      for(int ele:nums){
        s.insert(ele);
        int k=ele*(-1);
        if(s.count(k)){
            maxele=max(maxele,abs(k));
        }
      }
      return maxele;
    }
};