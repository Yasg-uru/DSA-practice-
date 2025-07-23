const int MOD = 1e9+7;

class Solution {
public:
    static constexpr array<int, 100000> precomputeFactorials() {
        array<int, 100000> factorials;
        long long current = 1;
        factorials[0] = 1;
        for (int i = 1; i < 100000; i++) {
            current *= i;
            if (current >= MOD) current %= MOD;
            factorials[i] = current;
        }
        return factorials;
    }

    static inline long long powerMod(long long base, unsigned exponent, int modVal = MOD) {
        if (exponent == 0) return 1;
        int numBits = 31 - countl_zero(exponent);
        bitset<32> bitMask(exponent);
        long long result = base;
        for (int i = numBits - 1; i >= 0; i--) {
            result = (result * result % modVal) * (bitMask[i] ? base : 1) % modVal;
        }
        return result;
    }

    static inline int modularInverse(int value, int modVal = MOD) {
        int coeffA = 1, coeffB = 0;
        int remA = value, remB = modVal;
        while (remB != 0) {
            int quotient = remA / remB, tempRem = remB, tempCoeff = coeffB;
            remB = remA - quotient * remB;
            coeffB = coeffA - quotient * coeffB;
            remA = tempRem;
            coeffA = tempCoeff;
        }
        if (coeffA < 0) coeffA += modVal;
        return coeffA;
    }

    static long long combination(int total, int choose, auto& factorials) {
        return 1LL * factorials[total] * modularInverse(factorials[choose]) % MOD * modularInverse(factorials[total - choose]) % MOD;
    }

    static int countGoodArrays(int length, int colors, int special) {
        static constexpr auto factorials = precomputeFactorials();
        return colors * powerMod(colors - 1, length - special - 1) % MOD * combination(length - 1, special, factorials) % MOD;
    }
};
