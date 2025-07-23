class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0,currentWindowSum=0,result=0;
        set<int>s;
        int n=nums.size();
        while(j<n){
            while(s.count(nums[j])){
                currentWindowSum-=nums[i];
                s.erase(nums[i]);
                i++;

            }
            s.insert(nums[j]);
            currentWindowSum+=nums[j];
            if(j-i+1==k){
                result=max(result ,currentWindowSum);
                currentWindowSum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
            j++;
        }
return result;
    }
};