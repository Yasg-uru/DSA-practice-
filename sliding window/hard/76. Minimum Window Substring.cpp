
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            // Edge case: If `s` is smaller than `t`, no valid window can exist.
            if (s.size() < t.size()) {
                return "";
            }
            
            unordered_map<char, int> mp; // Frequency map for characters in `t`
            for (char ch : t) {
                mp[ch]++;
            }
            
            int i = 0, j = 0; // Two pointers for the sliding window
            int n = s.size();
            int required_count = t.size(); // Number of characters still needed to form a valid window
            int minWindowSize = INT_MAX; // Stores the minimum window length found
            int start_i = -1; // Stores the starting index of the minimum window
            
            while (j < n) {
                char char_j = s[j];
                
                // If `char_j` is needed, decrement the required count
                if (mp[char_j] > 0) {
                    required_count--;
                }
                mp[char_j]--; // Reduce frequency of `char_j` in the map
                
                // Try to shrink the window from the left when all characters are matched
                while (required_count == 0) {
                    // Update minimum window size if a smaller valid window is found
                    if (j - i + 1 < minWindowSize) {
                        minWindowSize = j - i + 1;
                        start_i = i;
                    }
                    
                    // Remove `s[i]` from the window and update map
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) {
                        required_count++; // If `s[i]` was required, increase `required_count`
                    }
                    i++; // Move left pointer forward
                }
                j++; // Expand window from the right
            }
            
            // Return the minimum window substring found, or an empty string if no valid window exists
            return (minWindowSize == INT_MAX) ? "" : s.substr(start_i, minWindowSize);
        }
    };
    