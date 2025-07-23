class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(int i =0;i<s.length();i++){
            if(not st.empty() and isdigit(s[i])){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string ans ="";
        while(not st.empty()){
            ans+=st.top();
            st.pop();
        }
         reverse(ans.begin(),ans.end());
         return ans ;
    }
};