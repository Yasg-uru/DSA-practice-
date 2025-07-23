class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceChances =0 ,  bobChances =0 ;

        for(int i=1;i<colors.size()-1;i++){
            if(colors[i-1]==colors[i] and colors[i]==colors[i+1]){
                if(colors[i]=='A'){
                    aliceChances++;
                }else{
                    bobChances++;
                }
            }
        }
        return aliceChances>bobChances;
    }
};