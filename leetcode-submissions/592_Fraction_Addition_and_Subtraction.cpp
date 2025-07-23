class Solution {
public:
    string fractionAddition(string expression) {
        //simply we need to keep track on the signs 
        int i=0;
        int numerator=0;
        int denominator=1;
        while(i<expression.size()){
            int num=0;
            int den=0;
            bool isNeg=false;
            //if any sign is present in the string 
            if(expression[i]=='+' or expression[i]=='-'){
                if(expression[i]=='-'){
                    isNeg=true;
                }
                i++;
            }
            if(isNeg){
                num=num*-1;
            }
            while(i<expression.size() and isdigit(expression[i])){
                num=num*10+expression[i]-'0';
                i++;

            }
            i++;
             while(i<expression.size() and isdigit(expression[i])){
                den=den*10+expression[i]-'0';
                i++;

            }
            //we finds both num and den 
            numerator=numerator*den+num*denominator;
            denominator=denominator*den;

            

            
        }
        numerator=abs(numerator);
        int gcdval=gcd(numerator,denominator);
        numerator/=gcdval;
        denominator/=gcdval;
        return to_string(numerator)+"/"+to_string(denominator);
    }
};