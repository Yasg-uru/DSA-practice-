class Solution {
public:
    int n ;
    vector<int>dp;
    int getNextJobIndex(int l, vector<vector<int>>&arr, int currentJobEnd){
        int r= n-1;
        int result =n+1;
        while(l<=r){
            int mid= l+(r-l)/2;
            if(arr[mid][0]>=currentJobEnd){
                result = mid;
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>&arr, int i ){
        if(i>=n) return 0 ;
       if(dp[i]!=-1) return dp[i];
        int nextJobIndex = getNextJobIndex(i+1 , arr, arr[i][1]); // we need to find the next jobs after the current job subarray
        int take = arr[i][2]+solve(arr, nextJobIndex);
        int not_take = solve(arr, i+1);
        return dp[i]=max(take , not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n= startTime.size();
        vector<vector<int>> arr(n, vector<int>(3)); 
        dp.clear();
        dp.resize(n+1,-1);
        for(int i=0;i<n;i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];

        }
        sort(arr.begin(), arr.end());
        return solve(arr,0);
    }
};