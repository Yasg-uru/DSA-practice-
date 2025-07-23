class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int ,int >mp;
        for(int num:nums){
            mp[num]++;
        }
        int maxAns =0 , n =nums.size();
        sort(nums.begin(), nums.end());
        for(int i =0 ;i<n-1;i++){
            if((nums[i+1]-nums[i])==1){
                maxAns =max(maxAns , (mp[nums[i+1]]+mp[nums[i]]));
            }
        }
        return maxAns  ;
    }
};