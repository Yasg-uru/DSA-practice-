class Solution {
public:
    int n ;
    bool canDistribute(int c,vector<int>& candies, long long k){
        long long count = 0;
            for(int i=0;i<n;i++){
                count+=(candies[i]/c);
            }
            if(count>=k){
                return true;
            }
            return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int maxC = 0 ;
        n = candies.size();
        int totalCandies = 0 ;
        for(int i=0;i<n;i++){
            totalCandies+=candies[i];
            maxC= max(maxC, candies[i]);
        }
        if(totalCandies<k){
            return 0 ;
        }

        int left = 1;
        int right = maxC;
        int result = 0;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(canDistribute(mid, candies, k)){
                result = mid ;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return result ;
    }
};