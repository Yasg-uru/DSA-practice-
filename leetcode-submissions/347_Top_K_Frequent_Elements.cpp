class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        if(nums.size()==1){
            ans.push_back(nums[0]);
            return ans;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;//we are storing frequency and element

        }
        for(auto ele:mp){
            if(ele.second>1){
                ans.push_back(ele.first);
            }
        }
        return ans;
    }
};