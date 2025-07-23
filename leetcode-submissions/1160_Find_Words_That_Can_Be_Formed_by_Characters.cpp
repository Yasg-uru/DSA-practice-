class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_set<char>characters(chars.begin(),chars.end());
        int ans =0;
        for(int i=0;i<words.size();i++){
            bool isPossible =true ;
            for(char ch :words[i]){
                if(!characters.count(ch)){
                    isPossible=false;
                    break;
                }
            }
                if(isPossible){
                    ans+=words[i].size();
                }
        }
        return ans ;
    }
};