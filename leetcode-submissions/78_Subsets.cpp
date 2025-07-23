class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        return createsubsets(nums,0,temp,ans);
    }
};