class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int day = 1;
        int count =0 ;
        int i =0;
        while(i<events.size()){
            if(events[i][0]<=day and day<=events[i][1]){
                count++;
            }
            day++;
            i++;
        }
        return count ;
    }
};