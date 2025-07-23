class Solution {
public:
    int n ;
     vector<vector<int>>ans;
    void solve(vector<int>&candidates, int target , int i , vector<int>&temp){
        if(i>=n or target<0){
            return ;
        }
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(candidates[i]);
        solve(candidates, target-candidates[i], i, temp);
        temp.pop_back();
        solve(candidates, target, i+1, temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        n= candidates.size();
        solve(candidates, target, 0 , temp);
        return ans ;
    }
};