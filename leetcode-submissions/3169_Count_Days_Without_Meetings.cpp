class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] < b[0];
            });

  // Track the current occupied day and available days count.
  int current_occupied_day = 0;
  int available_days = 0;

  for (const auto& meeting : meetings) {
    // Check if there's a gap between the previous meeting and this one.
    if (meeting[0] > current_occupied_day) {
      // Add the gap days to available days (excluding meeting days).
      available_days += meeting[0] - current_occupied_day - 1;
    }

    // Update current occupied day to the end of the meeting.
    current_occupied_day = std::max(current_occupied_day, meeting[1]);
  }

  // Check for available days after the last meeting.
  if (days > current_occupied_day) {
    available_days += days - current_occupied_day;
  }

  return available_days;
    }
};