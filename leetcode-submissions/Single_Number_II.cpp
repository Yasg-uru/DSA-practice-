class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int>mp;
        for(int& n : nums){
            mp[n]++;
        }
        for(auto ele : mp){
            if(ele.second==1){
                return ele.first;
            }
        }
        return -1;
    }
};