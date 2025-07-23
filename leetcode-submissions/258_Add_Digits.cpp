class Solution {
public:
    int addDigits(int n) {
        while(n>10 ){
        int newNum =0 ;
            while(n){
                int lastDigit = n%10;
                n = n/10;
                newNum+=lastDigit ;
            }
            n = newNum;
        }
        return n ;
    }
};