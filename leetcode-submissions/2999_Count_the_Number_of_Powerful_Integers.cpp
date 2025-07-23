class Solution {
public:
    int solve(string str , int limit , string inputSuffix ){
        if(str.length()<inputSuffix.length()){
            return 0 ;

        }
        string trailingStr= str.substr(str.length()- inputSuffix.length());
        int remainingLength = str.length()-inputSuffix.length();
        int count =0 ;

        for(int i=0;i<remainingLength;i++){
            int digit = str[i]-'0';
            if(digit<=limit){
                count+=digit*pow(limit+1, remainingLength-i-1);
            }else{
                count+=pow(limit+1, remainingLength-i);
            }
        }
        if(trailingStr>=inputSuffix){
            count+=1;
        }
        return count ;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string finishStr = to_string(finish);
        return solve(finishStr , limit , s )- solve(startStr , limit , s); 
    }
};