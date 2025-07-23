class Solution {
public:
    long long countGoodIntegers(int numLength, int divisor) {
        unordered_set<string> uniqueDigitPermutations;

        int halfLength = (numLength + 1) / 2;
        int startNum = pow(10, halfLength - 1);
        int endNum = pow(10, halfLength) - 1;

        for (int leftHalfNum = startNum; leftHalfNum <= endNum; leftHalfNum++) {
            string leftHalfStr = to_string(leftHalfNum);
            string fullPalindrome = "";

            if (numLength % 2 == 0) {
                string rightHalfStr = leftHalfStr;
                reverse(rightHalfStr.begin(), rightHalfStr.end());
                fullPalindrome = leftHalfStr + rightHalfStr;
            } else {
                string rightHalfStr = leftHalfStr.substr(0, halfLength - 1);
                reverse(rightHalfStr.begin(), rightHalfStr.end());
                fullPalindrome = leftHalfStr + rightHalfStr;
            }

            long long palindromeNum = stoll(fullPalindrome);
            if (palindromeNum % divisor != 0)
                continue;

            sort(fullPalindrome.begin(), fullPalindrome.end());
            uniqueDigitPermutations.insert(fullPalindrome);
        }

        vector<long long> factorialLookup(11, 1);
        for (int i = 1; i < 11; i++) {
            factorialLookup[i] = factorialLookup[i - 1] * i;
        }

        long long totalCount = 0;
        for (const string &digits : uniqueDigitPermutations) {
            vector<int> digitFrequency(10, 0);
            for (const char &digitChar : digits) {
                digitFrequency[digitChar - '0']++;
            }

            int totalDigits = digits.length();
            int zerosCount = digitFrequency[0];
            int nonZeroStartOptions = totalDigits - zerosCount;

            long long permutations = (nonZeroStartOptions * factorialLookup[totalDigits - 1]);

            for (int i = 0; i < 10; i++) {
                permutations /= factorialLookup[digitFrequency[i]];
            }

            totalCount += permutations;
        }

        return totalCount;
    }
};
