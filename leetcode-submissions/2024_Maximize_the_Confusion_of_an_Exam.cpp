class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
    
        int i = 0 ;
        int n = answerKey.size();
        int j = 0 ;
        int maxTrue = 0;
        int maxFalse= 0 ;
        int c = 0;
        while(j<n){
            if(answerKey[j]=='F'){
                c++;
            }
            while(c>k){
                if(answerKey[i]=='F'){
                    c--;
                }
                i++;
            }
            maxTrue = max(maxTrue, j-i+1);
            j++;
        }
        i=0;
        j=0;
        c=0;
         while(j<n){
            if(answerKey[j]=='T'){
                c++;
            }
            while(c>k){
                if(answerKey[i]=='T'){
                    c--;
                }
                i++;
            }
            maxFalse = max(maxFalse, j-i+1);
            j++;
        }
        return max(maxFalse, maxTrue);
    }
};