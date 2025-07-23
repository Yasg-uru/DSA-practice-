class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int m = n-1;
        vector<int>pairs(m , 0);
        for(int  i=0;i<m;i++){
            pairs[i]= weights[i]+weights[i+1];
        }
        sort(pairs.begin(), pairs.end());
        int minSum = 0 ;
        int maxSum =0;
        for(int i=0;i<k-1;i++){
            minSum +=pairs[i];
            maxSum +=pairs[m-i-1];
        }
        return maxSum-minSum;
    }
};