class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue>=target){
            return startValue-target; // it gives number of the ones we need to add to make equal 

        }
        if(target%2==0){
            return 1+brokenCalc(startValue , target/2);

        }
        return 1+brokenCalc(startValue, target+1);
    }
};