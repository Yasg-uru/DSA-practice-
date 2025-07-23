class Solution {
public:
    vector<vector<int>>dp;
    int solve(int d, vector<int>& jd, int index, int n  ){
        //base case 
        //suppose if we have value of d =1 then we need to find the max of the remaining jobs 
        if(d==1){
            int maxD = jd[index];
            for(int i=index;i<n;i++){
                maxD= max(maxD, jd[i]);
            }
            return maxD;
        }
        if(dp[index][d]!=-1) return dp[index][d];
        // you need to find the maxD and then call for the next group 
        int maxD = jd[index];
        int finalAns = INT_MAX;
        for(int i=index;i<=n-d;i++){
            maxD = max(maxD, jd[index]);
            int result = maxD + solve(d-1, jd, i+1,n);
            finalAns= min(finalAns , result);
        }
        return dp[index][d]=finalAns ;
    }
    int minDifficulty(vector<int>& jd, int d) {
        dp.clear();
        dp.resize(jd.size()+1, vector<int>(d+1, -1));
        int n=jd.size();
        if(d>jd.size()) return -1;
        return solve(d, jd, 0,n);
    }
};