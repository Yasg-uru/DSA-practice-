class Solution {
public:
    // Checks if 'curr' repeated k times is a subsequence of 's'
    bool isSubSequence(string& s, int k, string& curr) {
        int len = curr.length();
        int i = 0, j = 0, n = s.length();

        while (i < n && j < k * len) {
            if (s[i] == curr[j % len]) {
                j++;
            }
            i++;
        }

        return j == k * len;
    }

    // Backtracking to try all valid strings using only allowed characters
    void backTracking(string& s, int k, string& result, string& curr,
                      vector<bool>& canUse, int maxLength, vector<int>& availableFreq) {
        
        if (curr.length() > maxLength) return;

        if ((curr.length() > result.length() || 
            (curr.length() == result.length() && curr > result)) && 
            isSubSequence(s, k, curr)) {
            result = curr;
        }

        for (int i = 25; i >= 0; --i) { // loop from z to a for lexicographical priority
            if (!canUse[i] || availableFreq[i] == 0) continue;

            char ch = 'a' + i;
            curr.push_back(ch);
            availableFreq[i]--;

            backTracking(s, k, result, curr, canUse, maxLength, availableFreq);

            curr.pop_back();
            availableFreq[i]++;
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> availableFreq(26, 0);
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canUse[i] = true;
                availableFreq[i] = freq[i] / k;
            }
        }

        int maxLength = s.length() / k;
        string result = "", curr = "";
        backTracking(s, k, result, curr, canUse, maxLength, availableFreq);

        return result;
    }
};
