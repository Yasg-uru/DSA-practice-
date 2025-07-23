class Solution {
public:
    const int MOD = 1e9+7;
    int findPower(long long a , long long b){
        if(b==0){
            return 1;
        }
        long long  half  = findPower(a, b/2);
        long long  result =  (half*half)%MOD;
        if(b%2==1){
            result= (result*a)%MOD;
        }
        return result ;

    }
    int countGoodNumbers(long long n) {
        long long    evenCount = (n+1)/2;
        long long    oddCount = n/2;
        
       return (long long )findPower(5, evenCount ) * findPower(4, oddCount)%MOD;
    }
};