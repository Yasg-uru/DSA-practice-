class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
vector<int>ansfreq(26,INT_MAX);
vector<string>ans;
for(int i=0;i<words.size();i++){
        vector<int>freq(26,0);
    for(char c:words[i]){
        freq[c-'a']++;
        
    }
    for(int i=0;i<26;i++){
ansfreq[i]=min(ansfreq[i],freq[i]);

    }
}
for(int i=0;i<26;i++){
    char ch=i+'a';
    while(ansfreq[i]>0){
ans.push_back(string(1,ch));
ansfreq[i]--;
    }
}
return ans;
    }
};