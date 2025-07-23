class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //for solving this question we need to take 3 variables and then tracjing can we give the combination of the sums 
        int a=0,b=0,c=0;
        for(int bill : bills){
            if(bill==5){
                a++;
            }else if(bill==10){
               b++;
               if(a>0){
                a--;
               } else {
                return false;
               }
            }else{

            c++;
            if(b>0 and a>0){
                a--;
                b--;
            }else if(a>=3 and b==0){
                a-=3;
            }else{
                return false;
            }
            }
        }
        return true ;

    }
};