class Solution {
public:
    int n ;
    vector<vector<int>>dp;

    int getIndex(vector<vector<int>>& events,int end, int start ){
        int l = start ;
        int r= n-1;
        int result = n;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(events[mid][0]>end){
                result= mid;
                r=mid-1;
            }else{
                l= mid+1;
            }
        }
        return result ;
    }
    int solve(vector<vector<int>>& events, int k, int i ){
        if(i>=n or k==0) return 0 ;
        if(dp[i][k]!=-1) return dp[i][k];

        int take = events[i][2]+solve(events, k-1, getIndex(events,events[i][1],i));
        int not_take = solve(events , k, i+1);
        return dp[i][k]=max(take , not_take);


    }
    int maxValue(vector<vector<int>>& events, int k) {
        n= events.size();
        dp.clear();
        dp.resize(n+1 , vector<int>(k+1, -1));
        sort(events.begin(), events.end());
        return solve(events , k, 0);

    }
};