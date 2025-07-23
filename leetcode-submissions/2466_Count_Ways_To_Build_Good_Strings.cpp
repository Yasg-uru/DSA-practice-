class Solution {
public:
    int solve(int length,int low ,int high,int zero,int one){
        if(length>high) return 0;
        bool isValid=false;
        if(length>=low and length<=high){
            isValid=true;
        }
        int append_zero=solve(length+zero,low,high,zero,one);
        int append_one=solve(length+one,low,high,zero,one);
        return isValid+append_zero+append_one;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        return solve(0,low,high,zero,one);
    }
};