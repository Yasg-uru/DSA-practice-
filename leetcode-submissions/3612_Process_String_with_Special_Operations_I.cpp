class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(char ch :s){
            if(ch=='*'){
                if(not result.empty()){
                    result.pop_back();
                    
                }
            }else if(ch=='#'){
                result = result+result;
            }else if(ch =='%'){
                reverse(result.begin(), result.end());
            }else{
                result.push_back(ch);
            }
        }
        return result ;
    }
};