class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        for(string& email : emails){
            size_t atPos = email.find('@');
            string local = email.substr(0 , atPos);
            string domain = email.substr(atPos+1);
            string modified_local = "";
            for(char& ch : local){
                if(ch=='.'){
                    continue;
                }else if(ch=='+'){
                    break;
                }
                
               modified_local+=ch;
            }
            modified_local+='@';
            modified_local+=domain;
            st.insert(modified_local);
        }
        return st.size();
    }
};