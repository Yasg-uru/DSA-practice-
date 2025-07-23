class Solution {
public:
void solve(int index,string digits,string ans,string *st,vector<string>&temp){
    if(index>=digits.size()){
        temp.push_back(ans);
        return;
    }
    int digitindex=digits[index]-'0';
    string val=st[digitindex];
    for(int j=0;j<val.size();j++ ){
ans.push_back(val[j]);
solve(index+1,digits,ans,st,temp);
ans.pop_back();
    }

}
    vector<string> letterCombinations(string digits) {
        vector<string>temp;
        if(digits==""){
            return temp;
        }
        string ans="";
        string st[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,ans,st,temp);
        return temp;
    }
};