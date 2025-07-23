class Solution {
public:
//global answer array 
vector<string>ans;
void solve(string &s ,int i,string sentence,vector<string>&wordDict,unordered_map<string,bool>&doesexist){
    //base case 
    if(i>=s.size()){
        ans.push_back(sentence.substr(1));
        return ;
    }
    for(int j=i+1; j<=s.size();j++){
        string word=s.substr(i,j-i);
        if(doesexist.find(word)!=doesexist.end()){
           
             solve(s,j,sentence+" "+word,wordDict,doesexist);
             
           /* int x=0;
            while(x<word.size()){
                x++;
                sentence.pop_back();
            }
            if(sentence.size()>0){
                sentence.pop_back();
            }*/
             
        }
    }

}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
unordered_map<string,bool>doesexist;
for(auto ele:wordDict){
    doesexist[ele]=true;

}
ans.clear();
string sentence="";

solve(s,0,sentence,wordDict,doesexist);
return ans;



    }
};