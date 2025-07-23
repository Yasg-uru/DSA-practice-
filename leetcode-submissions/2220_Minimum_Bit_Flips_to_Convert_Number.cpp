class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_value=start ^ goal;
        int ans=0;
        while(xor_value>0){
            ans+=xor_value & 1 ;
            xor_value=xor_value>>1;
        }
        return ans;
    }
};