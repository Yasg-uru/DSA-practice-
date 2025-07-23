class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
     if(points.size()==0){
        return 0;
     }   
     int arrow=1;
     int end=points[0][1];
     for(int i=0 ; i<points.size();i++){
        if(end>points[i][1]){
            arrow++;
            end=points[i][1];
        }
     }
     return arrow;
    }
};