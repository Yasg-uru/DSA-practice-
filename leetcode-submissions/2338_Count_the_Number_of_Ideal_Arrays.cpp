const int MOD = 1e9 + 7;
int factorialMemo[100000] = {};
int divisorDP[100000][15];
using ll = long long;

class Solution {
public:
    ll modPower(ll base, ll exponent, ll modulus = MOD) {
        ll result = 1;
        while (exponent > 0) {
            if (exponent & 1)
                result = (result * base) % modulus;
            base = (base * base) % modulus;
            exponent = exponent >> 1;
        }
        return result;
    }

    ll factorial(ll num) {
        if (num == 0) return 1;
        if (factorialMemo[num]) return factorialMemo[num];
        factorialMemo[num] = (num * factorial(num - 1)) % MOD;
        return factorialMemo[num];
    }

    ll modInverseCombination(ll total, ll select) {
        return (((factorial(total) * modPower(factorial(select), MOD - 2)) % MOD) * modPower(factorial(total - select), MOD - 2)) % MOD;
    }

    int idealArrays(int length, int maxValue) {
        for (int value = 1; value <= maxValue; value++)
            for (int size = 1; size <= min(length, 14); size++)
                divisorDP[value][size] = 0;

        for (int value = 1; value <= maxValue; value++) {
            divisorDP[value][1] = 1;
            for (int multiplier = 2; multiplier * value <= maxValue; multiplier++)
                for (int size = 1; size < min(length, 14); size++)
                    divisorDP[value * multiplier][size + 1] += divisorDP[value][size];
        }

        ll result = 0;
        for (int value = 1; value <= maxValue; value++)
            for (int size = 1; size <= min(length, 14); size++)
                result = (result + modInverseCombination(length - 1, length - size) * divisorDP[value][size]) % MOD;

        return result;
    } 
};
