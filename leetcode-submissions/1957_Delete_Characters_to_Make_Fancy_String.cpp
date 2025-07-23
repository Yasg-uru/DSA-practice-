class Solution {
public:
    string makeFancyString(string s) {
        // we need to iterate 3 steps back to the last character
      
        for(int i=0;i<s.size()-3;i++){
            while(s[i]==s[i+1] and s[i+1]==s[i+2]){
              s.erase(i,1); 
            }
        }
        return s;
    }
};