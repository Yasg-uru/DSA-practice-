class Solution {
public:
    bool isPrime(int n ){
        if(n<=1){
                return false;
        }
        for(int i = 2;i<n;i++){
            if(i%n==0){
                return false;
            }
        }
        return true ;
    }
    long long splitArray(vector<int>& nums) {
        int sum1 = 0 , sum2= 0;
        for(int i =0 ;i<nums.size();i++){
            if(isPrime(i)){
                sum1+=nums[i];
            }else{
                sum2+=nums[i];
            }
        }
        return abs(sum1-sum2);
    }
};