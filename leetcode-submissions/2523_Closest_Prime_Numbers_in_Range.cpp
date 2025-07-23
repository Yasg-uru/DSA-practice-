class Solution {
public:
    bool isPrime(int n ){
        if(n<2){
            return false ;

        }
        for(int i=2;i<n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true ;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans(2, -1);
        int minDiff= INT_MAX;
        vector<int>primes ;
        for(int num = left; num<=right ;num++){
            if(isPrime(num)){
                if(not primes.empty() and num-primes.back()<=2){
                    return {primes.back(), num};
                }
            primes.push_back(num);
            }
        }
        for(int i=1;i<primes.size();i++){
            int diff = primes[i]- primes[i-1];
            if(diff<minDiff){
                ans[0]= primes[i-1];
                ans[1]= primes[i];
                minDiff= diff;
            }
        }
        return ans ;
    }
};