class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeroesInNums1=0 , zeroesInNums2=0, sum1=0 , sum2=0 ;
        for(int n :nums1){
            if(n==0) {zeroesInNums1++;
             sum1+=1;
             }
            sum1+=n;
        }
        for(int n :nums2){
            if(n==0) {zeroesInNums2++; 
            sum2+=1;}
            sum2+=n;
        }
        if(sum1<sum2 and zeroesInNums1==0){
            return -1;
        }
        if(sum1>sum2 and zeroesInNums2==0){
            return -1;
        }
        return max(sum1, sum2);
    }
};