class Solution {
public:
void solve(int i,vector<int>&nums,vector<vector<int>>&ans){
    //base case
    if(i>=nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        solve(i+1,nums,ans);
        swap(nums[i],nums[j]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>temp;
        solve(0,nums,ans);

        for(auto it:ans){
            temp.insert(it);
        }
        vector<vector<int>>finalans;
        for(auto ele:temp){
            finalans.push_back(ele);

        }
        return finalans;
    }
};