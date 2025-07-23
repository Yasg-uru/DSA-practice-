class Solution {
public:
    vector<vector<int>>ans ;
    int n ;
    void solve(vector<int>&nums , int index , vector<int>&curr){
        if(curr.size()>=2){
            ans.push_back(curr);
        }
        unordered_set<int>isUsed;
       for(int i=index;i<n;i++){
         if(curr.empty() or (curr.back()<=nums[i]) and (isUsed.find(nums[i])==isUsed.end())){
            curr.push_back(nums[i]);
            solve(nums , i+1, curr);
            curr.pop_back();
            isUsed.insert(nums[i]);
        }
       }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n= nums.size();
        ans.clear();
        vector<int>curr;
        solve(nums , 0 , curr);
        return ans ;
    }
};