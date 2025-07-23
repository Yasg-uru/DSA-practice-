class Solution {
public:
    long long minimumSteps(string s) {
        long long  counter=0;
        long long answer=0;
        for(int i=s.size()-1 ;i>=0;i--){
            if(s[i]=='0'){
                counter++;
            }else{
                answer+=counter;
            }
        }
        return answer;
    }
};