class Solution {
public:
int calculate(int v1,int v2,string op){
    if(op=="-"){
        return (v1-v2);
    }else if(op=="/"){
        return (v1/v2);
    }else if(op=="+"){
        return (v1+v2);
    }else {
        return (v1*v2);
    }

}

    int evalRPN(vector<string>& tokens) {
      stack<int>st;
      for(int i=0;i<tokens.size();i++){
          string str=tokens[i];
         if(str=="+" or str=="-" or str=="/" or str=="*"){
             int v1=st.top();
             st.pop();
             int v2=st.top();
             st.pop();
             st.push(calculate(v2,v1,str));
         }else{
            int n=stoi(str);
            st.push(n);
         }
      }  
      return st.top();
    }
};