class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token ;
        stack<string>st;
        while(getline(ss,token,'/')){
            if(token=="" or token==".") continue;
            if(token!=".." ){
                st.push(token);
            }else if(not st.empty()) {
                st.pop();
            }
        }
        string result = "";
        if(st.empty()) return "/";
        while(not st.empty()){
            result="/"+st.top()+result;
            st.pop();
        }
        return result;
    }
};