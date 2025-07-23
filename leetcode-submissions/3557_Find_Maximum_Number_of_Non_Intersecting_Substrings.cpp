class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b){
        return a[1]<b[1];
    }
    int maxSubstrings(string word) {
        unordered_map<char, vector<int>>mp;
        int n = word.size();
        
        for(int i =0 ;i<n;i++){
            char ch = word[i];
            mp[ch].push_back(i);
        }
        vector<vector<int>>intervals ;
        for(auto& ele : mp){
            vector<int>&vec = ele.second ;
            if(vec.size()==1 || vec.back()-vec[0]+1<4){
                continue;
            }
            intervals.push_back({vec[0], vec.back()});
            
            
        }
        if(intervals.empty()) return 0 ;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<vector<int>>result;
        result.push_back(intervals[0]);
        int Size = intervals.size();
        for(int i =1;i<Size;i++){
            if(intervals[i][0]>result.back()[1]){
                result.push_back(intervals[i]);
            }
        }
        return result.size();
    }
};