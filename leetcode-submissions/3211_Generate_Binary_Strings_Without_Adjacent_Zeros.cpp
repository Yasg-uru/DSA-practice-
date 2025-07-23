class Solution {
public:
void generateBinaryStrings(int n, std::string current, std::vector<std::string>& result) {
    // Base case: if the current string length is equal to n, add it to the result
    if (current.length() == n) {
        result.push_back(current);
        return;
    }

    // Append '1' to the current string and recurse
    generateBinaryStrings(n, current + "1", result);

    // Append '0' to the current string and recurse, only if the last character is not '0'
    if (current.empty() || current.back() != '0') {
        generateBinaryStrings(n, current + "0", result);
    }
}
    vector<string> validStrings(int n) {
         std::vector<std::string> result;
    generateBinaryStrings(n, "", result);
    return result;
    }
};