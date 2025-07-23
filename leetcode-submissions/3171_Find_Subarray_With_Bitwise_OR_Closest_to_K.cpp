class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        std::vector<int> prefix(nums.size(), 0);
  prefix[0] = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    prefix[i] = prefix[i - 1] & nums[i];
  }

  // Initialize variables for minimum difference and candidate subarray.
  int min_diff = std::numeric_limits<int>::max();
  std::pair<int, int> candidate_subarray = {-1, -1};

  // Iterate through the array considering all possible subarrays.
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i; j < nums.size(); ++j) {
      // Calculate the bitwise AND of the current subarray using the prefix array.
      int current_and = prefix[j];
      if (i > 0) {
        current_and &= ~prefix[i - 1];
      }

      // Calculate the absolute difference between k and the current AND.
      int current_diff = std::abs(k - current_and);

      // Update minimum difference and candidate subarray if a closer match is found.
      if (current_diff < min_diff) {
        min_diff = current_diff;
        candidate_subarray = {i, j};
      }
    }
  }

  return min_diff;
    }
};