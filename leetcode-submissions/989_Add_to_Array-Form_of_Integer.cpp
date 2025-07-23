class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry =0 , n = num.size();
        for(int  i =n-1;i>=0 and k>0 ;i--){
            int lastDigit = k%10;
            k/=10;
            int sum = lastDigit+carry+num[i];
            num[i] = sum%10;
            carry= sum/10;
        }
        if(carry>0){
            num.insert(num.begin(), carry);
        }
        return num ;
    }
};