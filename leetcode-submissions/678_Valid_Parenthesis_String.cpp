class Solution {
public:
    bool checkValidString(string s) {
        // now i am writing the solution of this question by using the stack approach in which i am using the two stacks one is open and second one is star
        stack<int>open;
        stack<int>star;
        for(int i=0;i<s.size();i++){
            //if we find the opening bracket then push into the open stack
            if(s[i]=='('){
                open.push(i);

            }else if(s[i]=='*'){
                star.push(i);

            }else if(not open.empty() and s[open.top()]=='(' and s[i]==')'){
                open.pop();

            }
        }
        //now writing the code for start case now we are travbersing full of the open stack 
        while(not open.empty()){
            if(star.empty()){
                return false;
            }
            else if(open.top()<star.top()){
                open.pop();
                star.pop();

            }else{
                return false;
            }
        }
        return true;
        
    }
};