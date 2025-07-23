class Solution {
public:
    int appendCharacters(string s, string t) {
        int sindex=0,tindex=0;
        int sLength=s.size();
        int tLength=t.size();
        while(sindex<sLength and tindex<tLength){
            if(s[sindex]==t[tindex]){
                tindex++;
            }
            sindex++;
        }
        return tLength-tindex;
    }
};