class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool isInBlock = false;
        vector<string>ans ;
        
        for(string& s : source){
            string currentLineCode ="";
            for(int i =0 ;i<s.length();i++){
                if(isInBlock){
                    if(i+1<s.length() and s[i]=='*' and s[i+1]=='/'){
                         isInBlock = false;
                        i++; //skipping the /
                    }
                }else{
                    if(i+1<s.length() and s[i]=='/' and s[i+1]=='*'){
                        break;
                        
                    }else if(i+1<s.length() and s[i]=='/' and s[i+1]=='/'){
                    isInBlock = true ;
                      i++; //skippinhg the star 
                    }else{
                    currentLineCode += s[i];
                    }
                }
            }
            if(not currentLineCode.empty()){
                ans.push_back(currentLineCode);
            }
        }
        return ans ;
    }
};