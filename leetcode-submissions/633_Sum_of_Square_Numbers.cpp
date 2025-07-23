class Solution {
public:
    bool judgeSquareSum(int c) {
       int left=0;
       int right=c-1;
       while(left<=right){
        if((left*left)+(right*right)==c){
            return true;
        }else if ((left*left)+(right*right)>c) {
right--;
        }else{

        left++;
        }
        
       }
       return false;
    }
};