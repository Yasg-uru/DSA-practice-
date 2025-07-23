class Solution {
public:
    bool isVowel(char ch ){
        return ch=='a' or ch=='e' or  ch=='i' or ch=='u' ;
    }
    int maxVowels(string s, int k) {
       int i = 0;
       int j =0 ;
       int n = s.length();
       int currWindowVowelCount = 0;
       int maxCount = 0 ;

       while(j<n){
        if(isVowel(s[j])){
            currWindowVowelCount++;
        }
        if(j-i+1==k){
            maxCount = max(maxCount , currWindowVowelCount);
            if(isVowel(s[i])){
                currWindowVowelCount--;
            }
            i++;
        }
        
        j++;

       }
       return maxCount;
    }
};