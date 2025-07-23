class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        const int n = plantTime.size();
        vector<pair<int , int >>vec(n);
        for(int i=0;i<n;i++){
            vec[i]= {plantTime[i], growTime[i]};
        }
        auto lamda= [](pair<int , int >p1, pair<int , int >p2){
            return p1.second>p2.second;
        };
        sort(vec.begin(), vec.end(), lamda);
        int maxBloomDays = 0 ;
        int prevPlantDays =0;

        for(int i=0;i<n;i++){
            int currPlantTime = vec[i].first;
            int currGrowTime = vec[i].second ;
            prevPlantDays+=currPlantTime;

            maxBloomDays = max(maxBloomDays, prevPlantDays+currGrowTime);
        }
        return maxBloomDays;
    }
};