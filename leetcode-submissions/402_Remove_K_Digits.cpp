class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";
        if(num.size()<=k){
            return "0";
        }
        if(k==0){
            return num;
        }
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<num.size();i++){
            while(k>0 and not st.empty() and num[i]<st.top()){
                --k;
                st.pop();
            }
                st.push(num[i]);
            if(st.size()==1 and num[0]=='0'){
                st.pop();
            }
        }
        while(k and not st.empty()){
            --k;
            st.pop();
        }
        while(not st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
    return res;
    }
};