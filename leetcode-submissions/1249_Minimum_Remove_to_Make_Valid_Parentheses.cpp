class Solution {
public:
    string minRemoveToMakeValid(string s) {
      stack<int>st;
      
      for(int i=0;i<s.size();i++){
          if(! isalpha(s[i])){
              if(st.empty()){
                  st.push(i);
              }else if(s[st.top()]=='(' && s[i]==')'){
                  st.pop();
              }else{
                  st.push(i);
              }
          }
      }  
      string ans=s;
      //unordered_set<int>indxtoremove;
      while(not st.empty()){
         int top=st.top();
         ans.erase(ans.begin()+top);
          st.pop();
      }
     

      return ans;
    }
};