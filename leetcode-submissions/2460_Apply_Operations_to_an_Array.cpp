class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        vector<int>ans ;
        for(int n :nums){
            if(n>0){
                ans.push_back(n);
            }

        }
        for(int n :nums){
            if(n==0){
                ans.push_back(n);
            }

        }
        return ans ;
        
    }
};