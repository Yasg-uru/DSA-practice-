class Solution {
public:
    string reverseStr(string s, int k) {
       vector<char>st;
       for(char ele:s){
st.push_back(ele);
       }
       for(int start=0;start<st.size();start+=2*k){
           int i=start;
           int j=min(start+k-1,st.size()-1);
           while(i<j){
               char temp=st[i];

           }
       }
    }
};