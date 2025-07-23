class Solution {
int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}
public:
    int maxLength(vector<int>& nums) {
     int n = nums.size();
    int max_len = 0;

    for (int i = 0; i < n; ++i) {
        int prod = 1;
        int current_gcd = nums[i];
        int current_lcm = nums[i];

        for (int j = i; j < n; ++j) {
            // Update product, gcd, and lcm iteratively
            prod *= nums[j];
            current_gcd = gcd(current_gcd, nums[j]);
            current_lcm = lcm(current_lcm, nums[j]);

            // Check the condition
            if (prod == current_gcd * current_lcm) {
                max_len = max(max_len, j - i + 1);
            }
        }
    }

    return max_len;    
    }
};