class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> found;
        int length = s.length();
        
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j <= length && j - i <= 30; j++) { // max 30 bits
                string sub = s.substr(i, j - i);
                
                // Skip leading zeros (except single '0')
                if (sub[0] == '0' && sub.length() > 1) continue;

                int val = stoi(sub, nullptr, 2);
                if (val >= 1 && val <= n) {
                    found.insert(val);
                }
            }
        }
        
        return found.size() == n;
    }
};
