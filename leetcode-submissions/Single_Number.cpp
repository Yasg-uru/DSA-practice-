class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // as we know that the xor cancels same number so if any number occurs more than once then it cancels it 
        int result = 0 ;
        for(int& num : nums){
            result ^= num;

        }
        return result ;
    }
};