class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int N = books.size();
        vector<int> dp(N+1, INT_MAX);

        // set the last element of the vector as '0'
        dp[N] = 0;

        for (int i=N-1; i>=0; i--){
            // Initialized variables
            int avail_width = shelfWidth;
            int max_height = 0;

            for (int j=i; j < N; j++){
                int width = books[j][0];
                int height = books[j][1];

                if (avail_width < width){
                    break;
                }
                
                avail_width -= width;
                max_height = max(max_height, height);
                dp[i] = min(dp[i], dp[j+1] + max_height);
            }
        }
        return dp[0];
    }
};