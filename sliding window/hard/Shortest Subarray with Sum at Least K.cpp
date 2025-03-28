#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefixSum(n + 1, 0);
        
        // Compute prefix sums
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        deque<int> dq; // Monotonic deque
        int minLength = INT_MAX;
        
        for (int j = 0; j <= n; j++) {
            // Maintain the shortest valid subarray
            while (!dq.empty() && prefixSum[j] - prefixSum[dq.front()] >= k) {
                minLength = min(minLength, j - dq.front());
                dq.pop_front();
            }
            
            // Maintain a monotonic increasing order in deque
            while (!dq.empty() && prefixSum[j] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(j);
        }
        
        return minLength == INT_MAX ? -1 : minLength;
    }
};
