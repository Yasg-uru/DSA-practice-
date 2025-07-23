class Solution {
public:
    int maxScore(string s) {
        int total_ones=0;
        int maxAns =INT_MIN;
        for(char ch:s){
            if(ch=='1') total_ones++;
        }
        int left_ones=0;
        int zeros_count =0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') {
                zeros_count++;
            }else {
                left_ones++;
            }
            int rightOnes=total_ones-left_ones;
            int score =zeros_count+rightOnes ;
            maxAns=max(maxAns,score);
        }
        return maxAns ;

    }
};