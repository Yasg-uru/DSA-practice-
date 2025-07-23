class Solution {
public:
    bool isCircularSentence(string sentence) {
        // we need to convert it into the string stream 
        vector<string>words;
        stringstream ss(sentence);
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        //after that we need to check whether the first and last character is same or not 
        if(words[0][0]!=words.back().back()){
            return false;

        }
        for(int i=0;i<words.size()-1;i++){
            if(words[i].back()!=words[i+1][0]){
                return false ;
            }
        }
        return true ;
    }
};