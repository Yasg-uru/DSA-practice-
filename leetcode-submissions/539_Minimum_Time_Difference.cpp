class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>times;
        for(int i=0;i<timePoints.size();i++){
            int hrs=std::stoi(timePoints[i].substr(0,2));
            int minutes=std::stoi(timePoints[i].substr(3,5));
            times.push_back(minutes);
            
        }
    }
};