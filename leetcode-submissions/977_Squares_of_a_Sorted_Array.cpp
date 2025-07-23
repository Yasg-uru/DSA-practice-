class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int left=0;
       vector<int>ans;
       int right=nums.size()-1;
       while(left<=right){
           if(abs(nums[left])>abs(nums[right])){
               ans.push_back((nums[left]*nums[left]));
               left++;

           }else{
               ans.push_back((nums[right]*nums[right]));
               right--;
           }
       } 
       sort(ans.begin(),ans.end());
       return ans;
    }
};