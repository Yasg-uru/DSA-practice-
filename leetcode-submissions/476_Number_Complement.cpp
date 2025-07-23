class Solution {
public:
static string digit_to_binary(int n){
    string binary="";
    while(n>0){
        binary=to_string(n%2)+binary;
        n/=2;
    }
    return binary;
}
static int binary_to_decimal(string binary){
    int Binary=stoi(binary);
    int decimal=0;
    int power=1;
    while(Binary>0){
        int lastdigit=Binary%10;
        decimal+=lastdigit*power;
        power*=2;
        Binary/=10;


    }
    return decimal ;
}


    int findComplement(int num) {
        string binary=digit_to_binary(num);
        for(int i=0;i<binary.size();i++){
            if(binary[i]=='0'){
binary[i]='1';
            }else {
                binary[i]='0';

            }
        }
        int decimal=binary_to_decimal(binary);
        return decimal;
    }
};