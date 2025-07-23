class Solution {
public:
    int length;
    int digitSumTotal;
    int MOD = 1e9 + 7;
    long long totalHalfPermutations = 0;

    // Binary exponentiation
    int powerMod(long long base, long long exp) {
        if (exp == 0) {
            return 1;
        }

        long long half = powerMod(base, exp / 2);
        long long result = (half * half) % MOD;
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    int dfs(int digitIdx, int evenCount, int currentSum,
            vector<int>& digitFrequency, vector<long long>& invFactorials,
            vector<vector<vector<int>>>& memo) {
        
        if (digitIdx == 10) {
            if (currentSum == digitSumTotal / 2 && evenCount == (length + 1) / 2) {
                return totalHalfPermutations;
            }
            return 0;
        }

        if (memo[digitIdx][evenCount][currentSum] != -1) {
            return memo[digitIdx][evenCount][currentSum];
        }

        long long totalWays = 0;

        for (int i = 0; i <= min(digitFrequency[digitIdx], (length + 1) / 2 - evenCount); i++) {
            int evenPos = i;
            int oddPos = digitFrequency[digitIdx] - i;

            long long divisor = (invFactorials[evenPos] * invFactorials[oddPos]) % MOD;

            long long result = dfs(digitIdx + 1, evenCount + evenPos, currentSum + digitIdx * i,
                                   digitFrequency, invFactorials, memo);

            totalWays = (totalWays + (result * divisor) % MOD) % MOD;
        }

        return memo[digitIdx][evenCount][currentSum] = totalWays;
    }

    int countBalancedPermutations(string number) {
        length = number.length();
        digitSumTotal = 0;

        vector<int> digitFrequency(10, 0);
        for (int i = 0; i < length; i++) {
            digitSumTotal += number[i] - '0';
            digitFrequency[number[i] - '0']++;
        }

        if (digitSumTotal % 2 != 0) {
            return 0;
        }

        // Precompute factorials
        vector<long long> factorial(length + 1, 1);
        for (int i = 2; i <= length; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        // Precompute modular inverses using Fermat's Little Theorem
        vector<long long> invFactorials(length + 1, 1);
        for (int i = 0; i <= length; i++) {
            invFactorials[i] = powerMod(factorial[i], MOD - 2) % MOD;
        }

        totalHalfPermutations = (1LL * factorial[(length + 1) / 2] * factorial[length / 2]) % MOD;

        vector<vector<vector<int>>> memo(10, vector<vector<int>>((length + 1) / 2 + 1, vector<int>(digitSumTotal + 1, -1)));
        return dfs(0, 0, 0, digitFrequency, invFactorials, memo);
    }
};
