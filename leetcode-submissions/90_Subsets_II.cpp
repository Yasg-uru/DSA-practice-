class Solution {
public:
set<vector<int>>st;
void helper(vector<int>&nums,vector<int>&temp,int i ,int n){
    //base case 
    if(i==n){
        st.insert(temp);
        return ;
    }
    helper(nums,temp,i+1,n);
    temp.push_back(nums[i]);
    helper(nums,temp,i+1,n);
    temp.pop_back();

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(nums,ans,temp,0,nums.size());
        for(auto ele:st){
            ans.push_back(ele);
        }

return  ans;

    }
};