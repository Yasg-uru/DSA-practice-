class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(char ch : address){
            if(ch=='.'){
                ans.push_back('[');
                ans.push_back('.');
                ans.push_back(']');
            }else{
                ans.push_back(ch);
            }
        }
        return ans ;
    }
};