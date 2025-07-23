class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> result(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {  // Fix: Use `>=` to handle duplicates
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl = getNSL(arr, n);
        vector<int> nsr = getNSR(arr, n);
        long long sum = 0;
        const int MOD = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            long long ls = i - nsl[i];
            long long rs = nsr[i] - i;
            long long totalWays = (ls * rs) % MOD;
            long long totalSum = (arr[i] * totalWays) % MOD;
            sum = (sum + totalSum) % MOD;
        }
        
        return sum;
    }
};
