class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int  n = nums.size()/2;
        unordered_map<int , int>mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto& ele : mp){
        if(ele.second==n){
            return ele.first;
            }
            }
        return  -1 ;
    }
};