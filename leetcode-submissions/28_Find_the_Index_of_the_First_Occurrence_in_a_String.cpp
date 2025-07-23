class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            int index=0;
            bool isFound=true ;
            for(int j=i;j<i+needle.size();j++){
                if(needle[index]!=haystack[j]){
                    isFound=false ;
                    break;
                }
                index++;
            }
            if(isFound){
                return i;
            }
        }
        return -1;
    }
};