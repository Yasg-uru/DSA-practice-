class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        int ans=0;
        int i=0;
        int j=tokens.size()-1;
        while(i<=j){
            if(tokens[i]<=power){
                
              
                if(ans<score){
                    ans=score;
                }
                power-=tokens[i];
                
            }else if(score>0){
                power+=tokens[j];
                score-=1;
                j--;
            }else {
                break;
            }
        }
        return ans;
    }
};