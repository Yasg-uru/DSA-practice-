// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       int firstBadVersion = -1;
        for(int i =1;i<=n;i++){
            bool isBad = isBadVersion(i);
            if(isBad){
                firstBadVersion = i ;
                break ;
            }
        }
        return firstBadVersion ;
    }
};