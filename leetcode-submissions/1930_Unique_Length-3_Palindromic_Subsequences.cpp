class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>letters(s.begin(),s.end());
        int count =0;
        for(char letter:letters){
            //then we need to check the first and last index of the characters 
            int firstIndex=s.find(letter);
            int lastIndex=s.rfind(letter);
            unordered_set<char>chars;
            for(int i=firstIndex+1;i<lastIndex;i++){
                chars.insert(s[i]);
            }
            count+=chars.size();
        }
        return count ;

    }
};