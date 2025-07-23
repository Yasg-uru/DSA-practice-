class Solution {
public:
    int maximumGain(string s, int x, int y) {
        //implementing this question by using the approach of stack 
       stack<char>st;

       int ans=0;
       if(y>x){
        
       for(int i=0;i<s.size();i++){
        if(not st.empty() and st.top()=='b' and s[i]=='a'){
            st.pop();
            ans+=y;

        }else{
            st.push(s[i]);

        }
       }
       string rem="";
       while(not st.empty()){
        rem.push_back(st.top());
        st.pop();
       }
       reverse(rem.begin(),rem.end());
       for(int i=0;i<rem.size();i++){
        if(not st.empty() and st.top()=='a' and rem[i]=='b'){
            st.pop();
            ans+=x;

        }else{
            st.push(rem[i]);

        }

       }
       }else{
         for(int i=0;i<s.size();i++){
        if(not st.empty() and st.top()=='a' and s[i]=='b'){
            st.pop();
            ans+=x;

        }else{
            st.push(s[i]);

        }
       }
       string rem="";
       while(not st.empty()){
        rem.push_back(st.top());
        st.pop();
       }
       reverse(rem.begin(),rem.end());
       for(int i=0;i<rem.size();i++){
        if(not st.empty() and st.top()=='b' and rem[i]=='a'){
            st.pop();
            ans+=y;

        }else{
            st.push(rem[i]);

        }

       }
       }
       return ans;
    }
};