class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int carry=0;
        int i=a.size()-1;
        int j=b.size()-1;
        while(i>=0 or j>=0 or carry>0){
            int digitA=(i>=0)?(a[i--]-'0'):0;
            int digitB=(j>=0)?(b[j--]-'0'):0;
            int sum=digitA+digitB+carry;
            carry=sum/2;
            res=to_string(sum%2)+res;
        }
        if(carry>0){
            res=to_string(carry)+res;
        }
        return res;
    }
};