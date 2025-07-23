class Solution {
public:
 vector<int>dp;
    int rec(string s,set<string>&uniqueEle,int index){
        if(index==s.size()){
            return 0; // now we have't any extra characters because string is ended
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int minCharacters=INT_MAX;
        for(int i=index;i<s.size();i++){
            //we need to find out the solution for every substring 
            string sb=s.substr(index,i-index+1);
            int extraChar=0;
            if(uniqueEle.find(sb)==uniqueEle.end()){
                extraChar=sb.size();
            }
            int currChar=rec(s,uniqueEle,i+1);
            minCharacters=min(minCharacters,currChar+extraChar);
        }
       return  dp[index]=minCharacters;

    }
    int minExtraChar(string s, vector<string>& dictionary) {
       dp.resize(50,-1);
        set<string>uniqueEle(dictionary.begin(),dictionary.end());
        return rec(s,uniqueEle,0);

    }
};