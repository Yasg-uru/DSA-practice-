class Solution {
public:
static int cal(int v1,int v2,char op){
    if(op=='+'){
        return (v1+v2);
    }
    if(op=='-'){
        return (v1-v2);
    }
    if(op=='/'){
        return (v1/v2);
    }
    if(op=='*'){
        return (v1*v2);
    }
}
static int precedence(char ch){
    if(ch=='/' or ch=='*'){
        return 3;
    }else if(ch=='+' or ch=='-'){
        return 2;
    }
    return 1;

}
    int calculate(string s) {
       stack<int>nums;
       stack<char>ops;
       for(int i=0;i<s.size();i++){
           char ch=s[i];
           if(isdigit(ch)){
               nums.push(ch-'0');
           }else if(ch==')'){
               while(not ops.empty() and not nums.empty() and ops.top()!='('){
                   int v2=nums.top();
                   nums.pop();
                   int v1=nums.top();
                   nums.pop();
                   char op=ops.top();
                   ops.pop();
                   nums.push(cal(v1,v2,op));
               }
               if(!ops.empty()){
                   ops.pop();
               }
           }else{
               while (not ops.empty() and precedence(ops.top()) >= precedence(ch))
            {
                int v2 = nums.top();
                nums.pop();
                int v1 = nums.top();
                nums.pop();
                char op = ops.top();
                ops.pop();
                nums.push(cal(v1, v2, op));
            }
            ops.push(ch);
        }
           }
       }
      /* while(! ops.empty()){
                char op = ops.top();
                ops.pop();
                int v2 = nums.top();
                nums.pop();
                int v1 = nums.top();
                nums.pop();
                nums.push(cal(v1, v2, op));
    }*/
    return nums.top(); 
    }
};