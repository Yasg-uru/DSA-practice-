class Solution {
public:
    int t[301];
bool solve(int index,string s ,unordered_set<string>&st){
    if(index>=s.length()){
        return true ;

    }
    if(t[index]!=-1){
        return t[index];
    }
    for(int l=1;l<=s.length();l++){
        string temp=s.substr(index,l);
        if(st.find(temp)!=st.end() and solve(index+l,s,st)){
            return t[index]=true ;
        }
    }
    return t[index]=false;

}
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t,-1,sizeof(t));
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        return solve(0,s,st);
        
    }
};