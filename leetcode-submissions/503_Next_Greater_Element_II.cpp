class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size()) ;
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            while(not st.empty() and nums[st.top()]<nums[i]){
                ans[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        // the above loop finds the next greater elements in the forward direction but we need to find for the last elment 
        while(not st.empty()){
            ans[st.top()]=-1;
            st.pop();
        }
        int lastIndex = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[lastIndex]<nums[i]){
                ans[lastIndex]=nums[i];
                break;
            }
        }
        return ans ;
    }
};