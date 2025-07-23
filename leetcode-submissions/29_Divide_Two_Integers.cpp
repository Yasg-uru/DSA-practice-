class Solution {
public:
    int divide(int dividend, int divisor) {
        long long  sum =0, count =0  ;
        while(sum<=dividend){
            sum+=abs(divisor);
            count++;
        }
        count--;
        return divisor<0?-count:count ;
    }
};