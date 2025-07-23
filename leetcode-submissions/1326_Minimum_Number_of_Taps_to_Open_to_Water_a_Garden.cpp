class Solution {
public:
    int gardenEnd ;
    int N ;
    unordered_map<int, unordered_map<int,int>>dp;
    int solve(vector<pair<int, int >>&pairs , int i , int maxEnd){
        
        if(i>=N){
            if(maxEnd>=gardenEnd) {
                return 0;
            }
            return 1e9;
        }
        if(dp.count(i) and dp[i].count(maxEnd)){
            return dp[i][maxEnd];
        }
        // in case if the current tap is not able to cover the full area means gap is formed then we can't able to water a ground
        if(pairs[i].first>maxEnd){
            return 1e9;
        }
        int take = 1+solve(pairs, i+1, max(maxEnd , pairs[i].second));
        int not_take = solve(pairs, i+1, maxEnd);
        return dp[i][maxEnd]= min(take , not_take);

    }
    int minTaps(int n, vector<int>& ranges) {
        N = ranges.size();
        gardenEnd= n;
        dp.clear();
        vector<pair<int, int >>arr;
        for(int i=0;i<ranges.size();i++){
            int start = max(0 , i-ranges[i]);
            int end = min(n, i+ranges[i]);
            arr.push_back({start, end});
        }
        sort(arr.begin(), arr.end());
        int minTaps= solve(arr, 0 , 0 );
        return minTaps==1e9?-1:minTaps;
    }
};