class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int requiredOccurence = (int)arr.size()*0.25;
        unordered_map<int, int >mp;
        for(int& n : arr){
            mp[n]++;
        }
        for(auto & ele : mp){
            if(ele.second>=requiredOccurence){
                return ele.first;
            }
        }
        return 0 ;
    }
};