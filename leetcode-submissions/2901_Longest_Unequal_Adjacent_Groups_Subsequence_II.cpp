class Solution {
public:
    bool checkHammingDistance(string&s1 , string &s2){
       int diff =0 ;
        for(int i =0 ;i<s1.length();i++){
                if(s1[i]!=s2[i]){
                    diff++;
                }
                if(diff>1) return false;
        }
        return diff ==1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<int>parent(n , -1), dp(n , 1);
        int longestSubSeqIndex  =0;
        int longestSubSeq = 1 ;
        for(int i =0 ;i<n;i++){
            for(int j =0;j<i;j++){
                if(groups[i]!=groups[j] and words[i].length()==words[j].length() and checkHammingDistance(words[i], words[j])){
                    if(dp[j]+1>dp[i]){
                        dp[i] = dp[j]+1;
                        parent[i] = j ;
                        if(dp[i]>longestSubSeq){
                            longestSubSeqIndex = i ;
                            longestSubSeq = dp[i];

                        }
                    }
                }
            }
        }
        vector<string>ans ;
        while(longestSubSeqIndex!=-1){
            ans.push_back(words[longestSubSeqIndex]);
            longestSubSeqIndex = parent[longestSubSeqIndex];

        }
        reverse(ans.begin(), ans.end());
        return ans ;
    }
};