class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        // a b c d 
        // b c d f
        // 1 1 1 2
        // 1 2 3 
        // l=0 2-0+1 =3
        int currcost=0;
        int left=0;
        int result=0;

        for(int i=0;i<s.size();i++){
            currcost+=abs(s[i]-t[i]);
            while(currcost>maxCost){
                currcost-=abs(s[i]-t[i]);
                left++;
            }
            result=max(result,i-left+1);

        }
return result;
    }
};