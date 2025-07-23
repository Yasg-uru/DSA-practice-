class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='c'){
                if(st.size()<2 or st.top()!='b') return false;
                st.pop();
                if(st.top()!='a') return false;
                st.pop();
            }else {
                st.push(s[i]);// if a or b then push it 

            }
        }
        return st.empty();
    }
};