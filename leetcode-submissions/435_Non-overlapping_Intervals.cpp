class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int lastpicked =0;
        int count=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[lastpicked][1]>intervals[i][0]){
                count++;
               
            }
            lastpicked=i;
        }
    return count;
    }
};