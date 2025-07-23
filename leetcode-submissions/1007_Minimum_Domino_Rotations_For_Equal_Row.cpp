class Solution {
public:
    int find(vector<int>&tops , vector<int>&bottoms, int val){
        int topSwaps  =0, bottomSwaps =0  ;
        for(int i =0 ;i<bottoms.size();i++){
            if(bottoms[i]!=val and tops[i]!=val){
                return -1;
            }
            else if(bottoms[i]!=val){
                bottomSwaps++;
            }else if(tops[i]!=val){
                topSwaps++;
            }
        }
        return min(topSwaps, bottomSwaps);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int minSwaps= INT_MAX;
        for(int val =1 ;val<=6;val++){
            int steps = find(tops , bottoms , val);
            if(steps!=-1){
                minSwaps= min(minSwaps , steps);

            }
        }
        return minSwaps==INT_MAX?-1:minSwaps;
    }
};