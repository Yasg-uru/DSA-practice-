class Solution {
public:
    unordered_map<int ,int >mp;
    Solution(vector<int>& nums) {
        for(int i =0 ;i<nums.size();i++){
            mp[nums[i]]= i ;
        }
    }
    
    int pick(int target) {
        return mp[target];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */