// class Solution {
// public:
//     int maxDistance(int side, vector<vector<int>>& points, int k) {
        
//     }
// };

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        // Sorting the points in a specific order
        auto sort_key = [side](const vector<int>& point) {
            int x = point[0], y = point[1];
            if (x == 0) return y;
            if (y == side) return side + x;
            if (x == side) return 3 * side - y;
            return 4 * side - x;
        };

        sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int>& b) {
            return sort_key(a) < sort_key(b);
        });

        // Binary search for the maximum possible minimum distance
        int left = 0, right = 2 * side, result = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canSelectKPoints(points, k, mid)) {
                result = mid;
                left = mid + 1; // Try for a larger distance
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

private:
    // Check if we can select k points with min distance >= d
    bool canSelectKPoints(const vector<vector<int>>& points, int k, int d) {
        int count = 1;
        vector<int> last_selected = points[0];

        for (size_t i = 1; i < points.size(); i++) {
            if (manhattanDistance(last_selected, points[i]) >= d) {
                count++;
                last_selected = points[i];
                if (count >= k) return true;
            }
        }

        return count >= k;
    }

    // Compute Manhattan distance
    int manhattanDistance(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};


