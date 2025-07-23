class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int ans=0;
        int maxI=-1;
        int minI=-1;
        int leftboundary=-1;
        for(int current=0;current<nums.size();current++){
            if(nums[current]==minK){
                minI=current;

            }
            if(nums[current]==maxK){
                maxI=current;
            }
            if(nums[current]<minK || nums[current]>maxK){
                leftboundary=current;
            }
            if(maxI!=-1 and minI!=-1){
                int smaller=min(maxI,minI);
                if((smaller-leftboundary)>0){
                    ans+=(smaller-leftboundary);

                }
            }

        }
        return ans;
    }
};