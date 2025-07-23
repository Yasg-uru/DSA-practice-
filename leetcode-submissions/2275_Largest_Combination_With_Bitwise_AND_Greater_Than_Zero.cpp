class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // we need to find out the condition where all the elements contains one bit at the particular position so we can find out the maximum number 
        vector<int>bits(32,0);
        for(int num:candidates){
            int j=0;
            // j specifies the position of the bits 
            while(num>0){
                bits[j++]+=num&1;
                //left shift
                num>>=1;
            }
            
        }
        int maxi=INT_MIN;

        for(int bit:bits){
            maxi=max(maxi,bit);
        }
        return maxi ;
    }
};