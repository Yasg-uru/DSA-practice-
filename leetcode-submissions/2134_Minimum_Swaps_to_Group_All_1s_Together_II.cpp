class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int windowSize=0;
        for(int num:nums){
            windowSize+=num;

        }
        int currZeros=0;
        for(int i=0;i<windowSize;i++){
            if(nums[i]==0){
                currZeros++;

            }
        }
        int start=0;
        int minZeros=currZeros;

        int n=nums.size();
        int end=windowSize-1;
        while(start<n){
            if(nums[start]==0){
                currZeros--;
            }
            start++;
            end++;
            if(nums[end%n]==0){
                currZeros++;
            }
            minZeros=min(minZeros,currZeros);
        }
        return minZeros;
    }
};