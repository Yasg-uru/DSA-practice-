class Solution {
public:
    const int MODULO = 1e9 + 7;
    
    long long powerCalc(long long base, long long exponent) {
        if (exponent == 0) return 1;
        long long halfPower = powerCalc(base, exponent / 2);
        long long result = (halfPower * halfPower) % MODULO;
        if (exponent % 2 == 1) {
            result = (result * base) % MODULO;
        }
        return result;
    }

    vector<int> generatePrimes(int upperLimit) {
        vector<bool> isPrime(upperLimit + 1, true);
        vector<int> primeList;

        for (int i = 2; i * i <= upperLimit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= upperLimit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= upperLimit; i++) {
            if (isPrime[i]) {
                primeList.push_back(i);
            }
        }

        return primeList;
    }

    vector<int> computePrimeScores(vector<int>& elements) {
        int size = elements.size();
        vector<int> primeScores(size, 0);

        int maxVal = *max_element(begin(elements), end(elements));
        vector<int> primeNumbers = generatePrimes(maxVal); //O(mloglogm)

        for(int i = 0; i < size; i++) { //O(n * log(m))
            int num = elements[i];

            for(int prime : primeNumbers) {
                if(prime * prime > num) {
                    break;
                }

                if(num % prime != 0) {
                    continue;
                }

                primeScores[i]++;
                while(num % prime == 0) {
                    num /= prime;
                }
            }
            if(num > 1) {
                primeScores[i]++;
            }
        }

        return primeScores;
    }

    vector<int> nextLargerElement(vector<int>& primeScores) {
        int size = primeScores.size();
        vector<int> nextGreater(size, size);
        stack<int> stk;

        for(int i = size - 1; i >= 0; i--) {
            while(!stk.empty() && primeScores[stk.top()] <= primeScores[i]) {
                stk.pop();
            }

            nextGreater[i] = stk.empty() ? size : stk.top();
            stk.push(i);
        }

        return nextGreater;
    }

    vector<int> prevLargerElement(vector<int>& primeScores) {
        int size = primeScores.size();
        vector<int> prevGreater(size, -1);
        stack<int> stk;

        for(int i = 0; i < size; i++) {
            while(!stk.empty() && primeScores[stk.top()] < primeScores[i]) {
                stk.pop();
            }

            prevGreater[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        return prevGreater;
    }

    int maximumScore(vector<int>& elements, int operationsLeft) {
        vector<int> primeScores = computePrimeScores(elements); //O(mloglogm + n*log(m))
        vector<int> nextGreater = nextLargerElement(primeScores); //O(n)
        vector<int> prevGreater = prevLargerElement(primeScores); //O(n)

        int size = elements.size();
        vector<long long> subarrays(size, 0);

        for(int i = 0; i < size; i++) { //O(n)
            subarrays[i] = (long long)(nextGreater[i] - i) * (i - prevGreater[i]);
        }

        vector<pair<int, int>> sortedElements(size);
        for(int i = 0; i < size; i++) {
            sortedElements[i] = {elements[i], i};
        }

        sort(begin(sortedElements), end(sortedElements), greater<>()); //O(nlogn)

        long long resultScore = 1;

        int index = 0;
        while(operationsLeft > 0) { //O(k * log(operations))
            auto [num, i] = sortedElements[index];

            long long possibleOps = min((long long)operationsLeft, subarrays[i]);

            resultScore = (resultScore * powerCalc(num, possibleOps)) % MODULO;

            operationsLeft -= possibleOps;
            index++;
        }

        return resultScore;
    }
};
