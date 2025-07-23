class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int j=0;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                swap(s[i],s[j]);
                j++;
            }
        }
        if(s.back()!='1'){
            swap(s[n-1],s[j-1]);
        }
        return s;
    }
};