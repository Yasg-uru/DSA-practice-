class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int operations  = 0;
        while(s.find("01")!=string::npos){
               operations++;
            for(int i =0 ;i<(int)s.length()-1;i++){
                

                if(s[i]=='0' and s[i+1]=='1'){
                    s[i]= '1';
                    s[i+1]= '0';
                 
                    i++;
                }
            }
        }
        return operations ;
    }
};