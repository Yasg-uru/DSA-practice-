class Solution {
public:

    int maximumLength(vector<int>& nums) {
   int count_even = 0;
        int count_odd = 0;

        // Counting even and odd numbers in the array
        for (int num : nums) {
            if (num % 2 == 0) {
                count_even++;
            } else {
                count_odd++;
            }
        }

        // Maximum length of a valid subsequence
        return min(count_even, count_odd) * 2;
    }
};