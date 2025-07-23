class Solution {
public:
    string decodeString(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                res.push_back(s[i]);
            }else{
                string st="";
                while(not res.empty() and res.back()!='['){
                    st.push_back(res.back());
                    res.pop_back();
                }
                reverse(st.begin(),st.end());
                res.pop_back();
                string num="";
                while(not res.empty() and res.back()>='0' and res.back()<='9'){
                    num.push_back(res.back());
                    res.pop_back();
                }
                reverse(num.begin(),num.end());
                int nums=stoi(num);
                if(nums!=0){

                while(nums--){
                    res=res+st;
                }
                }
            }
        }
        return res;
    }
};