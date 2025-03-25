
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Helper function to check if a character is a vowel
        bool isVowel(char ch) {
            ch = tolower(ch); // Convert to lowercase to handle both cases
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        }
    
        int maxVowels(string s, int k) {
            int i = 0, j = 0, n = s.length();
            int currWindowVowelCount = 0; // Stores the number of vowels in the current window
            int maxCount = 0; // Stores the maximum number of vowels found in any window
    
            while (j < n) {
                // If current character is a vowel, increase the count
                if (isVowel(s[j])) {
                    currWindowVowelCount++;
                }
    
                // If window size exceeds k, shrink it from the left
                if (j - i >= k) {
                    if (isVowel(s[i])) {
                        currWindowVowelCount--;
                    }
                    i++;
                }
    
                // Update maxCount after processing each valid window
                maxCount = max(maxCount, currWindowVowelCount);
                
                j++; // Expand the window
            }
    
            return maxCount;
        }
    };
    