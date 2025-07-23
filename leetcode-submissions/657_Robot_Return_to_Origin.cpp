class Solution {
public:
    bool judgeCircle(string moves) {
        int pos =0 ;
        for(char move : moves){
            if(move=='U') pos++;
            if(move=='D') pos--;
            if(move=='L') pos--;
            if(move=='R') pos++;
        }
        return pos==0;
    }
};