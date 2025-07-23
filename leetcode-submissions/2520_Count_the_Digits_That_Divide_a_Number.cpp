class Solution {
public:
    int countDigits(int num) {
        int number = num, count =0  ;
        while(number>0){
            int lastDigit = number%10;
            if(num%lastDigit==0){
                count++;
            }
            number/=10;
        }
        return count ;
    }
};