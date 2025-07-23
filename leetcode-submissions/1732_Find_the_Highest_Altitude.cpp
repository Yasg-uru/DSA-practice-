class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        // vector<int>prefixSum(n+1, 0);
        int currSum=0, maxAns =0  ;
        for(int i =0 ;i<n;i++){
            currSum+=gain[i];
            // prefixSum[i]= currSum;
            // cout<<"sum:"<<prefixSum[i]<<" ";
            maxAns = max(maxAns , currSum);
        }

        return maxAns ;

    }
};