class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>result;
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(result.back()[1]>intervals[i][0]){
                result.back()[0] = min(intervals[i][0], result.back()[0]);
                result.back()[1]= max(intervals[i][1], result.back()[1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result ;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // we need to create two intervals array one for x axis and another for y axis and check whether the atleast three cuts can be made on any of them 
        vector<vector<int>>x_axis, y_axis;
        // [startx, starty, endx, endy]
        // [x1, y1, x2, y2]
        for(int i=0;i<rectangles.size();i++){
            int x1 = rectangles[i][0];
            int y1 = rectangles[i][1];
            int x2 = rectangles[i][2];
            int y2 = rectangles[i][3];
            x_axis.push_back({x1, x2});
            y_axis.push_back({y1 , y2});
        }
        vector<vector<int>>result1 = merge(x_axis);
        vector<vector<int>>result2 = merge(y_axis);
        return result1.size()>=3 or result2.size()>=3;
    }
};