#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Merges overlapping intervals in a given list of intervals.
     * 
     * @param intervals A vector of intervals, where each interval is a pair [start, end].
     * @return A vector of merged intervals.
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {}; // Edge case: if no intervals are provided

        // Sort intervals by their start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]); // Initialize result with the first interval

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = result.back(); // Get reference to last merged interval

            if (last[1] >= intervals[i][0]) { // If overlapping, merge intervals
                last[0] = min(last[0], intervals[i][0]);
                last[1] = max(last[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]); // Otherwise, add a new interval
            }
        }

        return result;
    }
};
