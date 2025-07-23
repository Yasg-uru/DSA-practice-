/*class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        
    }
};*/

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long result = 0;

        for (auto& word : words) {
            vector<int> lps = computeLPS(word);
            result += countValidPairs(lps);
        }

        return result;
    }

private:
    vector<int> computeLPS(const string& pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    long long countValidPairs(const vector<int>& lps) {
        long long result = 0;
        int n = lps.size();

        for (int i = 1; i < n; i++) {
            result += lps[i];
        }

        return result;
    }
};