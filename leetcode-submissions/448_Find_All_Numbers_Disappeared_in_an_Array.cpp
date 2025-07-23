class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //now using unorderd set for finding the solution
        unordered_set<int>s(nums.begin(),nums.end());
        vector<int>ans(nums.size()-s.size());
        int j=0;
        for(int i=1;i<=nums.size();i++){
            if(!s.count(i)){
                ans[j++]=i;
            }
        }
        return ans;
    }
};