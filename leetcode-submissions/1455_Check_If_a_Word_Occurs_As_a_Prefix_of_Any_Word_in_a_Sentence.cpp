class Solution {
public:
    bool is_found(string word,string prefix){
        string temp="";
        for(char ch:word){
            if(temp==prefix){
                return true ;
            }
            temp+=ch;
        }
        return false;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int index=1;
        //time complexity =o(n)
        stringstream ss(sentence);
        string word;
        while(ss>>word){
            if(is_found(word,searchWord)){
                return index;
            }
            index++;
        }
        return -1;
    }
};