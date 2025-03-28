#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0), f2(26, 0);
        int n = s2.length(), m = s1.length();
        
        // Frequency count of s1
        for (char ch : s1) {
            f1[ch - 'a']++;
        }
        
        // Sliding window approach
        for (int i = 0; i < n; i++) {
            f2[s2[i] - 'a']++;
            
            // Maintain window size equal to s1
            if (i >= m) {
                f2[s2[i - m] - 'a']--;
            }
            
            // Check if current window matches s1 frequency
            if (f1 == f2) {
                return true;
            }
        }
        
        return false;
    }
};
