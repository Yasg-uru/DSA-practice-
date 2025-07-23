class Solution {
public:
    int n ;
    int t[100001];

    int solve(int i , vector<int>&arr, int& diff){
        if(i>=n) return 0 ;
        int result = 0 ;
        if(t[i]!=-1) return t[i];
        for(int j=i+1;j<n;j++){
            int prev = arr[i];
            int curr = arr[j];
            if((curr-prev)==diff){
                result= max(result , 1+solve(j, arr, diff));
            }
        }
        return t[i]= result ;
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        int result = 0 ;
        n= arr.size();
        memset(t, -1, sizeof(t));
        for(int i=0;i<arr.size();i++){
            result =max(result , 1+solve(i, arr, difference));
        }
        return result ;

    }
};