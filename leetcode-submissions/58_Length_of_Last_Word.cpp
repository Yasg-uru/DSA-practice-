class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                int j=i;
                while(s[j]!=' '){
                    length++;
                    j--;
                }
            break;
            }
        }
        return length;
    }
};