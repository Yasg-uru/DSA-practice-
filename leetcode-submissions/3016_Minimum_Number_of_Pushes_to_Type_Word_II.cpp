class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char ch:word){
            freq[ch-'a']++;
        }
        int ans =0;
sort(freq.begin(),freq.end(),greater<int>());//sorting in decreasing order because we need to use greedy approach 
        for(int i=0;i<26;i++){
            if(i<8){
                ans+=freq[i];
            }else if( i<16){
                ans+=freq[i]*2;
            }else if(i<24){
                ans+=freq[i]*3;
            }else {
                ans+=freq[i]*4;
            }
        }
        return ans ;
    }
};