class Solution {
public:
    string makeGood(string s) {
        if(s.size()<=1){
            return s;
        }
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(not st.empty() and toupper(st.top())==s[i] ){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(not st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};