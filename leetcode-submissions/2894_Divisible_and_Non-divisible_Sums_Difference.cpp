class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1Sum =0 , num2Sum=0 ;
        for(int i =1;i<=n;i++){
            if(i%m==0){
num2Sum+=i;

            }else{
                num1Sum+=i;
            }
        }
        return num1Sum-num2Sum;
    }
};