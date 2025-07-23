class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[k];
                if(sum==0){
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(sum<0){
                    j++;
                }else{
                    k--;
                }

            }
        }
        vector<vector<int>>arr(ans.begin(),ans.end());
        return arr;
    }
};