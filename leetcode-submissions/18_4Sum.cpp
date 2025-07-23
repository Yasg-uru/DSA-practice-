class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int c=j+1;
                int d=n-1;
                while(c<d){
                    int sum=nums[i]+nums[j]+nums[c]+nums[d];
                    if(sum==target){
                        ans.insert({nums[i],nums[j],nums[c],nums[d]});
                        c++;
                        d--;
                    }else if(sum>target){
                        d--;
                    }else{
                        c++;
                    }
                }
            }
        }
        vector<vector<int>>arr(ans.begin(),ans.end());
        return arr;
        
    }
};