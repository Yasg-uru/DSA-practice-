class Solution {
public:
    string reverseWords(string s) {
        int start=0;
        for(int end=0;end<s.size();end++){
            if(s[end]==' ' or end==s.size()-1){
                int i=start;
                int j=(end==static_cast<int>(s.size()-1))?end:end-1;
                while(i<j){
                    swap(s[i++],s[j--]);
                }
                start=end+1;
            }
        }
        return s;
    }
};