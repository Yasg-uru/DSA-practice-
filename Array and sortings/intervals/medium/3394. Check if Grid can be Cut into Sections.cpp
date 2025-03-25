#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = result.back();

            if (last[1] >= intervals[i][0]) {  // Merge overlapping intervals
                last[0] = min(last[0], intervals[i][0]);
                last[1] = max(last[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_axis, y_axis;

        // Extract x and y axis intervals
        for (const auto& rect : rectangles) {
            x_axis.push_back({rect[0], rect[2]});
            y_axis.push_back({rect[1], rect[3]});
        }

        // Merge intervals
        vector<vector<int>> merged_x = merge(x_axis);
        vector<vector<int>> merged_y = merge(y_axis);

        // Check if at least three non-overlapping cuts can be made
        return merged_x.size() >= 3 || merged_y.size() >= 3;
    }
};
