class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int result = 1;

        for(int i=0;i<nums.size();i++){
            int mask = 0 ;

            for(int j = i ;j<nums.size();j++){
                if((mask & nums[j])!=0){
                    break;
                }
                result = max(result , j-i+1);
                mask= (mask | nums[j]);
            }
        }
        return result ; 
    }
};