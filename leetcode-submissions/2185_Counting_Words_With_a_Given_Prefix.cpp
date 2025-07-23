class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int preflength=pref.size();
        int ans=0;
        for(int i=0;i<words.size();i++){
if(pref==words[i].substr(0,preflength)){
    ans++;

}
        }
        return ans;
    }
};