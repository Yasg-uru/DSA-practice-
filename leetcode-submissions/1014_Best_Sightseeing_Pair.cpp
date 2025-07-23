class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int>vec(values.size());
        for(int i=0;i<values.size();i++){
           if(i==0){
            vec[i]=values[i];
           }else {
            int val=values[i]+i;
            vec[i]=max(vec[i-1],val);
           }
        }
        int maxScore=INT_MIN;

        for(int i=1;i<values.size();i++){
            int sightseeingPair=vec[i-1]+(values[i]-i);
            maxScore=max(maxScore,sightseeingPair);
        }
        return maxScore==INT_MIN?0:maxScore;
    }
};