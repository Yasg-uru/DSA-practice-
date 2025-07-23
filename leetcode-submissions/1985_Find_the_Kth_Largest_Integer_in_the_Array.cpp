class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
      priority_queue<int>pq;
      for(int i=nums.size()-1;i>=0;i--){
          int num=stoi(nums[i]);
          pq.push(num);
          
      } 
      while(k>1){
          pq.pop();
          k--;
      }
      string ans=to_string(pq.top());
      return ans; 
    }
};