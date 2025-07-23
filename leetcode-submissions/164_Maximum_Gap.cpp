class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        int maxele=0;

        for(int i=0;i<nums.size()-1;i++){
            maxele=max(maxele,(nums[i+1]-nums[i]));
        }
        return maxele;
    }
};