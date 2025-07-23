class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string result ="";
        for(int i=0;i<s.length();i++){
            if(!isdigit(s[i])){
                result+=s[i];
            }else {
                string str = "";
                while(not result.empty()){
                    str=result.back()+str;
                    result.pop_back();
                }
                int n = s[i]-'0';
                while(n--){
                    result+=str;
                    if(result.length()>=k) break;
                }
            }
        }
        cout<<result;
        k--;
        return string(1,result[k]);
    }
};