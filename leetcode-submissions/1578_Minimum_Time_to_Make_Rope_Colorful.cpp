class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prevMax = 0 ;
        int time =0;
        for(int i=0;i<colors.size();i++){
            if(i>0 and  colors[i]!=colors[i-1]){
                prevMax = 0 ;

            }
            int currTime = neededTime[i];
            time+=min(prevMax , currTime);
            prevMax= max(prevMax , currTime);
        }
        return time ;
    }
};