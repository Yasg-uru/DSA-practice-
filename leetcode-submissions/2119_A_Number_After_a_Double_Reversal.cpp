class Solution {
public:
    bool isSameAfterReversals(int num) {
        int reversed=0 ;
        int n = num ;

        while(n){
            reversed= reversed*10+(n%10);
            n/=10;
        }
        n = reversed;
        int reversed2= 0 ;
        while(n){
            reversed2= reversed2*10+(n%10);
            n/=10;
        }

        return num==reversed2;
    }
};