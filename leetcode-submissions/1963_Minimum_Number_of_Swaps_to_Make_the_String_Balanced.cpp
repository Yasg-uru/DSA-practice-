class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                st.push(s[i]);
            }else{
                if(not st.empty() and st.top()=='['){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        int a=0;
        int b=0;
        while(not st.empty()){
            if(st.top()=='['){
                b++;
            }else{
                a++;
            }
            st.pop();
        }
        return (((a+1)/2)+((b+1)/2))/2;
    }
};