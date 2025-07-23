class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        //now we need to make a loop in which column number is greater than 0
        while(columnNumber>0){
            int remainder=(columnNumber-1)%26;
            res=static_cast<char>('A'+remainder)+res;
            columnNumber=(columnNumber-1)/26;
        }
        return res;
    }
};