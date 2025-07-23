class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = stoi(num1);
        int n2 = stoi(num2);
        return to_string(n1*n2);
    }
};