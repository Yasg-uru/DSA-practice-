class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalSum = 0 ;
        for(int& n : nums){
            totalSum+=n;
        }
        int remainder = totalSum%k;
        return remainder;
    }
};