class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], x2 = rec1[2], y1 = rec1[1], y2 = rec1[3];
        int x3 = rec2[0], x4 = rec2[2], y3 = rec2[1], y4 = rec2[3];
        return not (
        x2<=x3 or x4<=x1 or y2<=y3 or y4<=y1
        );
    }
};