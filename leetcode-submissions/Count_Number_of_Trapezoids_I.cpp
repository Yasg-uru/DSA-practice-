class Solution {
public:
        long long MOD = 1e9+7;
    
    int countTrapezoids(vector<vector<int>>& points) {
        map<int , int >y_axis_counts;
        for(auto& point : points){
            y_axis_counts[point[1]]++;
        }
        long long total = 0 ;
        long long lowerSeg= 0;
        for(auto& ele : y_axis_counts){
            int y = ele.first ;
            int freq = ele.second ;
            if(freq<2){
                continue ;
            }
            long long currSeg = (long long)freq*(freq-1)/2;
            long long newTrapezoids = (currSeg*lowerSeg)%MOD;
            total = (total+newTrapezoids)%MOD;
            lowerSeg = (lowerSeg+currSeg)%MOD;
        }
        return (int)total;
    }
};