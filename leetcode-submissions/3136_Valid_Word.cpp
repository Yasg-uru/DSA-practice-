class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' or ch=='e' or ch=='i' or ch =='o' or ch == 'u' or ch=='a' or ch=='E' or ch=='I' or ch =='O' or ch == 'U';
    }
    bool isConsonent(char ch){
        return ch!='a' and ch!='e' and  ch!='i' and ch !='o' and  ch != 'u' and ch!='a' and ch!='E' and ch!='I' and  ch !='O' and ch != 'U';
    }
    bool isValid(string word) {
        if(word.length()<3){
            return false;
        }
        // checking for the digit 
        bool isDigitPresent = false;
        for(char ch: word){
            if(isdigit(ch)){
                isDigitPresent = true ;
            }
        }
        if(not isDigitPresent){
            return false;
        }
        //checking for the vowels
        bool isVowelPresent = false;
        for(char ch:word){
            if(isVowel(ch)){
                isVowelPresent= true ;
            }
        }
        if(not isVowelPresent){
            return false;
        }
         bool isCons= false;
        for(char ch : word){
            if(isalpha(ch) and  isConsonent(ch)){
                isCons= true;
            }
        }
        if(not isCons){
            return false;
        }
        return true ;
    }
};