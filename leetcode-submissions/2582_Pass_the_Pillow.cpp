class Solution {
public:
    int passThePillow(int n, int time) {
        //solving thie question by using the flag approach
        int counter=0;
        bool flag=false;
        for(int i=0;i<=time;i++){
            if(flag){
                counter=counter-1;
            }
            if(flag==false){
                counter=counter+1;

            }
            if(counter==n){
                flag=true;
            }

        }
        return counter;
    }
};