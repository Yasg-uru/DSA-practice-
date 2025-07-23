class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string>st(dictionary.begin(),dictionary.end());
        stringstream s(sentence);
        string ans;
string word;
        while(s >> word){
            bool flag=false;
            string str;
            for( char ch:word){
                str+=ch;
                if(st.count(str)){
                    flag=true;
                    break;

                }
            }
            ans+=(flag?str:word);
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};
