class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int maxPickedNum = INT_MIN;
        for(int i = 1;i<num.size()-1;i++){
            if(num[i-1]==num[i] and num[i]==num[i+1] and maxPickedNum<(int)(num[i]-'0')){
                maxPickedNum = (int)(num[i]-'0');
                ans = string(3, num[i]);
            }
        }
        return ans ;
    }
};