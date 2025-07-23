class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        bool isNegative = num<9;
        num = abs(num);
        while(num>0){
            ans+=to_string(num%7);
            num/=7;
        }
        if(isNegative) ans+="-";
        reverse(ans.begin(), ans.end());
        return ans ;
    }
};