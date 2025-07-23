class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int n = words.size();
        unordered_set<string>conversions;
        for(string& word:words){
            string temp = "";
            for(char& ch : word){
                int index = ch-'a';
                //we need to get the indexed string and then concatenate them
                temp+=codes[index];
            }
            conversions.insert(temp);
        }
        return conversions.size();
    }
};