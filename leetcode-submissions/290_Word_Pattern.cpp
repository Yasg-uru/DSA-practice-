class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //now we need to create two maps first is chartoword and secondone is wordtochar
unordered_map<char,string>chartoword;
unordered_map<string,char>wordtochar;

       istringstream ss(s);
        string word;
        int i=0;
        while(ss>>word){
            if(i>=pattern.size()){
                return false;
            }
            char ch=pattern[i];
            if(chartoword.find(ch)==chartoword.end() and wordtochar.find(word)==wordtochar.end()){
                chartoword[ch]=word;
                wordtochar[word]=ch;
            }else if(chartoword[ch]!=word and wordtochar[word]!=ch){
                return false;
            }
            i++;

        }
        return i==pattern.size();
    }
};