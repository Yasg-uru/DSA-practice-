class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for(int i=0;i<shifts.size();i++){
            int start=shifts[i][0];
            int end =shifts[i][1];
            int direction=shifts[i][2];
            for(int i=start;i<=end;i++){
                if(direction==1){
                if(s[i]=='z'){
                    s[i]='a';
                }else {
                    s[i]++;
                }

                }else {
                if(s[i]=='a'){
                    s[i]='z';
                }else {
                    s[i]--;
                }
                }
            }
        }
        return s;
    }
};