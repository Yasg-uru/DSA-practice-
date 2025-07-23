class Solution {
public:
    vector<int> evenOddBit(int n) {
        int index =0 ;
        vector<int>counts(2, 0 );
        while(n){
            if(n&1){
                if(index%2==0){
                    counts[0]++;
                }else{
                    counts[1]++;
                }
            }
            index++;
            n>>=1;
        }
        return counts ;
    }
};