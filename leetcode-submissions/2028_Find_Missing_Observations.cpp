class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        //Calculate total sum of the existing array
        for(auto& x : rolls)
        {
            sum += x;
        }
        //Calculate sum required for the missing rolls
        int missing_Sum = (m + n) * mean - sum;
        //When outside the range return null
        if(missing_Sum < n || missing_Sum > 6 * n)
        {
            return {};
        }
        int avg = missing_Sum / n;
        int balance = missing_Sum % n;
        vector<int> ans(n, avg); //vector initialize all elements with the average value
        // Distribute the remainder by incrementing the first 'balance' elements
        for(int i = 0; i < balance; i++)
        {
            ans[i]++;
        }
        return ans;
    }
};