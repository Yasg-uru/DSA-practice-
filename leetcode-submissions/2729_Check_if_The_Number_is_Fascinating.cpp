class Solution {
public:
    bool isFascinating(int n) {
        int firstNumber = 2*n;
        int secondNumber = 3*n;
        string s =to_string(n)+ to_string(firstNumber)+to_string(secondNumber);
        for(char ch : s){
            if(ch<'1' or ch>'9' ){
                return false;
            }
        }
        
        return true ;
    }
};