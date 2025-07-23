class Solution {
public:
    vector<pair<char, int>> getGroups(const string& s) {
        vector<pair<char, int>> groups;
        int i = 0;
        while (i < s.size()) {
            char c = s[i];
            int count = 0;
            while (i < s.size() && s[i] == c) {
                i++;
                count++;
            }
            groups.push_back({c, count});
        }
        return groups;
    }

    int expressiveWords(string s, vector<string>& words) {
        auto sGroups = getGroups(s);
        int stretchyCount = 0;

        for (string& word : words) {
            auto wGroups = getGroups(word);
            if (sGroups.size() != wGroups.size()) continue;

            bool stretchy = true;
            for (int i = 0; i < sGroups.size(); ++i) {
                char sc = sGroups[i].first;
                int scnt = sGroups[i].second;
                char wc = wGroups[i].first;
                int wcnt = wGroups[i].second;

                if (sc != wc) {
                    stretchy = false;
                    break;
                }

                if (scnt < 3 && scnt != wcnt) {
                    stretchy = false;
                    break;
                }

                if (scnt >= 3 && wcnt > scnt) {
                    stretchy = false;
                    break;
                }
            }

            if (stretchy) stretchyCount++;
        }

        return stretchyCount;
    }
};
