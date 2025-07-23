class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // in this question basically they asked to exchange the empty water bottles to get one new filled bottle 
        int ans = numBottles; // in the start drink all the bottles 
        int emptyBottles = numBottles; //then all the bottles are empty and we need to exchange these bottles 
        
        while(emptyBottles>=numExchange){
            int newRifills = emptyBottles/numExchange;
           ans+=newRifills;
            emptyBottles = (emptyBottles%numExchange) + newRifills;
            
            
            
            
        }
        
        return ans ;
    }
};