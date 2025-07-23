class Solution {
public:
static bool solveExpression(vector<bool>vals,char operator){
    bool ans=true;
    if(operator=='&'){
for(bool val:vals){
    ans=ans & val;
}

    } else if(operator=='|'){
        for (bool val:vals){
            ans=ans | val;
        }
    }
    else if(operator=='!'){
        return !vals[0];
    }
}
    bool parseBoolExpr(string expression) {
        // now we need to use the stack to solve this question because this is based on the parenthesis based 
        stack<char>st;
        for(int i=0;i<expression.size();i++){
            if(expression[i]==')'){
                    // we need to wait until we dont find the open bracket 
                    while(not st.empty() and st.top()=='('){
                        
                    }
            }else{
                st.push(expression[i]);
            }
        }
        return ans;
    }
};