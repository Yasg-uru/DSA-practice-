class Solution {
public:
    int result = INT_MIN ;
    int m ;
    void solve(int index , vector<vector<int>>& requests, vector<int>&resultant, int count,int n ){
        if(index>=m){
            bool isAllZero= true ;
            for(int i=0;i<n;i++){
                if(resultant[i]!=0){
                    isAllZero= false;
                    break;
                }
            }
            if(isAllZero){
                result = max(result , count);

            }
            return ;

        }
        int from = requests[index][0];
        int to = requests[index][1];
        resultant[from]--;
        resultant[to]++;
        solve(index+1, requests, resultant, count+1, n);
        resultant[from]++;
        resultant[to]--;
        solve(index+1, requests, resultant , count , n);
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>resultant(n, 0 );
        m= requests.size();

        solve(0 ,requests, resultant, 0,n  );
        return result ;
    }
};