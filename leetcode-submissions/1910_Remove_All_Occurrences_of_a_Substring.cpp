class Solution {
public:
    bool check(stack<char>st, string part ){
        for(int i=part.length()-1;i>=0;i--){
            if(st.top()!=part[i]){
                return false;
            }
            st.pop();
        }
        return true ;
    }
    string removeOccurrences(string s, string part) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            st.push(s[i]);
            if(st.size()>=part.length() and check (st,part)){
                for(int j=0;j<part.length();j++)
                {
                        st.pop();
                        
                }            
            }
        }
        string result = "";
        while(not st.empty())
        {
            result+=st.top();
            st.pop();


        }
        reverse(result.begin(),result.end());
        return result;

    }
};