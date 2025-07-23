class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int ele:nums){
            mp[ele]++;
        }
        vector<int>ans;
        for(auto ele:mp){
            if(ele.second>(n/3)){
                ans.push_back(ele.first);
            }
        }
        return ans;
    }
};