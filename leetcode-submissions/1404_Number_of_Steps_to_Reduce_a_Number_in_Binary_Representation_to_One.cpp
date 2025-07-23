class Solution {
public:
    int numSteps(string s) {
        
        int carry =0;
        int step=0;
        for(int i=s.size()-1;i>0;i--){
            step++;
            int currentvalue=s[i]-'0'+carry;
            if(currentvalue%2==1){
                carry=1;
                step++;
            }
        }
        return step+carry;
    }
};