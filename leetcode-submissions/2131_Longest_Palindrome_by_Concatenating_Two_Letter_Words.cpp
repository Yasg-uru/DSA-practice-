class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string , int >mp;
        for(auto& word :words){
            mp[word]++;
        }
        int result =0;
        bool isCenterUsed= false;
        for(string& word : words){
            string rev = word;
            reverse(begin(rev), end(rev));
            if(word!=rev){
                if(mp[word]>0 and mp[rev]>0){
                    mp[word]--;
                    mp[rev]--;
                    result+=4;

                }
            }else{
                if(mp[word]>=2){
                    mp[word]-=2;
                    result+=4;
                }else if(mp[word]==1 and isCenterUsed==false){
                    isCenterUsed = true ;
                    result+=2;
                    mp[word]--;
                }
            }
        }
        return result;

    }
};