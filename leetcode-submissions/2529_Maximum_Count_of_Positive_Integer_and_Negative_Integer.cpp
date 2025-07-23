class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCount =0;
        int negCount =0;
        int maxCount = 0 ;
        for(int n :nums){
            if(n<0){
                negCount++;
            }else if(n>0){
                posCount++;
            }
            maxCount = max({maxCount , posCount , negCount});
        }
        return maxCount ;
    }
};