class Solution {
public:
    bool isConsecutive(char a , char b){
        int difference = abs(a-b);
        if(difference==1 or difference==25){
            return true ;
        }
        return false;
    }
    string resultingString(string s) {
        stack<char>st;
        for(char ch :s){
            if(not st.empty() and isConsecutive(st.top() , ch)){
                st.pop();
                
            }else{
                st.push(ch);
            }
        }
        string ans = "";
        
        while(not st.empty()){
        ans+=st.top();
            st.pop();
            
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};