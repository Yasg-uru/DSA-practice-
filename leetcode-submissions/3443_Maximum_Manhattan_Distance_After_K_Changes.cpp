class Solution {
public:
    int maxDistance(string s, int k) {
        int east =0 , west =0 , north =0 , south =0 ;
        int maxDistance =0, n = s.length() ;
        for(int i =0;i<n;i++ ){
            if(s[i]=='E') east++;
            else if (s[i]=='W') west++;
            else if(s[i]=='N') north++;
            else if (s[i]=='S') south++;
            int currDistance = abs(east- west)+abs(north-south);
            int steps = i+1;
            int wasted_steps = steps-currDistance;
            int extra = 0 ;
            if(wasted_steps!=0){
                extra+=min(2*k , wasted_steps);
            }
            maxDistance = max(maxDistance , extra+currDistance);

        }
        return maxDistance ;
    }
};