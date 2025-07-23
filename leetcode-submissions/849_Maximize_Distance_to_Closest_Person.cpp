class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        bool hasLeadingZeroes = false, hasTrailingZeroes = false;
        int maxAns = INT_MIN;
        int n = seats.size();
        for(int i =0 ;i<n;i++){
            if(seats[i]!=0){
                hasLeadingZeroes = true ;
            }
            if(not hasLeadingZeroes){
                maxAns =max(maxAns , i+1);
            }
            
        }
        for(int i = n-1;i>=0;i--){
             if(seats[i]!=0){
                hasTrailingZeroes = true ;
            }
            if(not hasTrailingZeroes){
                maxAns = max(maxAns , n-i);
            }
        }
        int prev1Index = -1;
        for(int i=0 ;i<n;i++){
            if(prev1Index ==-1 and seats[i]==1){
            prev1Index=i;
                
            }else if(prev1Index!=-1 and seats[i]==1) {
                int AvailableSeats = i-prev1Index ;
                maxAns = max(maxAns , AvailableSeats/2);
                prev1Index =i ;
                
            }
            
        }
        return maxAns ;
    }
};