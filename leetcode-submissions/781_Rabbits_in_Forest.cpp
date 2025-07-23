class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int , int >mp; // represents rabbit count 
        for(int& ans : answers){
            mp[ans]++;
        }
        int ans =0 ;
        for(auto& ele : mp){
            int groupSize = ele.first+1 ; //because each rabbit says that mere jaise or hai 
            int reporties = ele.second ;
            int numberOfGroups = (int)ceil(reporties*1.0 /groupSize*1.0);
            ans+=(numberOfGroups*groupSize);
        }
        return ans ;
    }
};