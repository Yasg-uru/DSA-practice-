class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int count =0 ;
        int n = words.size();
        for(int i =0 ;i<n;i++){
            for(int j= i+1;j<n;j++){
                string word = words[j];
                reverse(word.begin(), word.end());
                if(words[i]==word){
                    count++;
                }
            }
        }
        return count ;
    }
};