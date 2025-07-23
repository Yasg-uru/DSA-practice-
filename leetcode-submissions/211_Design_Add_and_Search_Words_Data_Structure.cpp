class WordDictionary {
public:
    unordered_set<string>words ;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        int n = word.size();
        words.insert(word);
        
        for(int i =0 ;i<n;i++){
        string temp = word;
        temp[i]= '.';
            words.insert(temp);
        }
        for(int i =0 ;i<n;i++){
for(int j =i+1 ;j<n;j++){
string temp = word;
temp[i]= '.';
    temp[j]= '.';
    words.insert(temp);
}
            }
    }
    
    bool search(string word) {
        return (words.find(word)!=words.end());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */