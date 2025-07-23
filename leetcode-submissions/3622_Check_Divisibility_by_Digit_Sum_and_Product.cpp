class Solution {
public:
    bool checkDivisibility(int n) {
        int digit_sum  =0 ;
        int temp =n;
        while(temp){
            digit_sum+=(temp%10);
            temp/=10;
        }
        temp = n;
        int digit_product=1;
        while(temp){
            digit_product*=(temp%10);
            temp/=10;
        }
        return (n%(digit_product+digit_sum)==0);
    }
};