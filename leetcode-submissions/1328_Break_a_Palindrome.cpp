class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();

    if (n == 1) {
        return "";
    }

    // Check first half of the string
    for (int i = 0; i < n / 2; i++) {
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
    }

    // If all characters are 'a' in the first half
    palindrome[n - 1] = 'b';
    return palindrome;
    }
};