class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
         int result = 0;
        int n = min(arr1.size(), arr2.size());

        for (int i = 0; i < n; ++i) {
            string str1 = to_string(arr1[i]);
            string str2 = to_string(arr2[i]);

            int j = 0;
            while (j < min(str1.length(), str2.length()) && str1[j] == str2[j]) {
                ++j;
            }

            result = max(result, j);
        }

        return result;
    }
};