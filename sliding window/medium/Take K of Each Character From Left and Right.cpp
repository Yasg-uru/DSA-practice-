#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int a_count = 0, b_count = 0, c_count = 0;
        int n = s.length();
        
        // Count occurrences of 'a', 'b', and 'c'
        for (char ch : s) {
            if (ch == 'a') a_count++;
            if (ch == 'b') b_count++;
            if (ch == 'c') c_count++;
        }
        
        // If any character appears less than k times, return -1
        if (a_count < k || b_count < k || c_count < k) {
            return -1;
        }
        
        int i = 0, j = 0;
        int max_valid_window = INT_MIN;
        
        // Sliding window approach
        while (j < n) {
            // Remove the current character from counts
            if (s[j] == 'a') a_count--;
            if (s[j] == 'b') b_count--;
            if (s[j] == 'c') c_count--;
            
            // If we have removed too many of any character, shrink the window from the left
            while (i <= j && (a_count < k || b_count < k || c_count < k)) {
                if (s[i] == 'a') a_count++;
                if (s[i] == 'b') b_count++;
                if (s[i] == 'c') c_count++;
                i++;
            }
            
            // Update the max valid window size
            max_valid_window = max(max_valid_window, j - i + 1);
            j++;
        }
        
        // Minimum characters to delete = total length - max valid window size
        return (n - max_valid_window);
    }
};
