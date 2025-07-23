class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxD=INT_MIN;
        for(int i=0;i<arrays.size()-1;i++){
            vector<int>first=arrays[i];
            vector<int>second=arrays[i+1];
            for(int r=0;r<first.size();r++){
                for(int c=0;c<second.size();c++){
                    int dis=abs(first[r]-second[c]);
                    maxD=max(maxD,dis);
                }
            }
        }
        return maxD;
    }
};