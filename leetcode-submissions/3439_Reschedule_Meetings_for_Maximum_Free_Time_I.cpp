class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
          int n = startTime.size();
        vector<pair<int, int>> meetings;
        
        // Store meetings as {start, end} pairs
        for (int i = 0; i < n; i++) {
            meetings.push_back({startTime[i], endTime[i]});
        }
        
        // Compute the original free time intervals
        vector<int> freeTimes;
        freeTimes.push_back(meetings[0].first);  // Free time before the first meeting
        
        for (int i = 1; i < n; i++) {
            freeTimes.push_back(meetings[i].first - meetings[i - 1].second);
        }
        
        freeTimes.push_back(eventTime - meetings[n - 1].second);  // Free time after last meeting
        
        // Find the maximum free time
        int maxFree = *max_element(freeTimes.begin(), freeTimes.end());

        // Try to shift at most k meetings to maximize free time
        for (int i = 0; i < n && k > 0; i++) {
            int leftLimit = (i == 0) ? 0 : meetings[i - 1].second;
            int rightLimit = (i == n - 1) ? eventTime : meetings[i + 1].first;
            
            int maxShiftLeft = meetings[i].first - leftLimit;
            int maxShiftRight = rightLimit - meetings[i].second;
            
            int shiftAmount = min(maxShiftLeft, maxShiftRight);
            
            if (shiftAmount > 0) {
                meetings[i].first -= shiftAmount;
                meetings[i].second -= shiftAmount;
                k--;
            }
        }

        // Recalculate free time after shifting
        freeTimes.clear();
        freeTimes.push_back(meetings[0].first);
        
        for (int i = 1; i < n; i++) {
            freeTimes.push_back(meetings[i].first - meetings[i - 1].second);
        }
        
        freeTimes.push_back(eventTime - meetings[n - 1].second);
        maxFree = *max_element(freeTimes.begin(), freeTimes.end());

        return maxFree;
    }
};