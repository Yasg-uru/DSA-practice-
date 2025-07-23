class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char , int >orderIndex ;
        
        for(int i =0 ;i<order.size();i++){
        orderIndex[order[i]] = i ;
        }
        for(int i =0 ;i<words.size()-1;i++){
            string word1 = words[i], word2= words[i+1];
            int minLength = min(word1.length(), word2.length());
            bool isValid = false;
            for(int j =0 ;j<minLength;j++){
                if(word1[j]!=word2[j]){
                    if(orderIndex[word1[j]]>orderIndex[word2[j]]){
                        return false;
                    }
                    isValid = true ;
                    break ; 
                }
            }
            if(not isValid and word1.length()>word2.length()){
                return false;
            }
        }
        return true ;
    }
};