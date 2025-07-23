class Solution {
public:
    bool isPerfectSquare(int num) {
        bool flag=false;
        for(int i=0;i<=num;i++){
            if((i*i)==num){
                flag=true;
            }
        }
        return flag;
    }
};