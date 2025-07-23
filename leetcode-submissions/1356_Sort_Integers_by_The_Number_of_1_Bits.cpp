class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a , int b){
            int bits_a = __builtin_popcount(a);
            int bits_b = __builtin_popcount(b);
            return bits_a==bits_b?a<b:bits_a<bits_b;
        });
        return nums;
    }
};