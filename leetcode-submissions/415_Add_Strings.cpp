class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        while(i>=0 or j>=0 or carry>0 ){
            if(i>=0){
                carry=carry+num1[i]-'0';
                i--;
            }
            if (j>=0){
                carry=carry+num2[j]-'0';
                j--;
            }
            ans+=static_cast<char>(carry%10+'0');
            carry=carry/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};