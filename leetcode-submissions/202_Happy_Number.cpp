class Solution {
public:
    bool isHappy(int n) {
       long long int sum=0;
        set<int>s;
        while(1){
            sum=0;
            while(n>0){
                int lastdigit=n%10;
                sum=sum+(lastdigit*lastdigit);
                n=n/10;

            }
            if(sum==1){
                return true;
            }
            if(s.count(sum)){
                return false;
            }else{
                s.insert(sum);
            }
            n=sum;
            
        }
        return true;
    }
};