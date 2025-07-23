class Solution {
public:
void  generateparenthesis(string op,int open ,int close,vector<string>&ans){
    if(open==0 and close==0){
        ans.push_back(op);
        return ;
    }
    if(open==close){
        string op1=op;
        op1.push_back('(');
        generateparenthesis(op1,open-1,close,ans);

    }
    else if(open==0 and close!=0){
        string op1=op;
        op1.push_back(')');
        generateparenthesis(op1,open,close-1,ans);
    }else if(open!=0 and close==0){
        string op1=op;
        op1.push_back('(');
        generateparenthesis(op1,open-1,close,ans);
    }else{
        string op1=op;
        string op2=op;
        op1.push_back('(');
        op2.push_back(')');
        generateparenthesis(op1,open-1,close,ans);
        generateparenthesis(op2,open,close-1,ans);
    }
}
    vector<string> generateParenthesis(int n) {
        //now we have a simple approach to solve this question we need to create a simple empty string and two counts for opening and closing bracket and one single vector
        string op="";
        int open=n;
        int close=n;
        vector<string>ans;
         generateparenthesis(op,open,close,ans);
         return ans;
    }
};