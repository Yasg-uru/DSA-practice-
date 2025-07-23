class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>ans ;
        int n = s.length(), i =0 ;
        while(i<n){
            int count =0 ;
            int prevIndex = i ;
            
            while(i<n and s[prevIndex]==s[i]){
                i++;
                count++;
            }
            
            if(count>=3){
                ans.push_back({prevIndex , i-1});
               
            }
           
            
            
            
        }
        return ans ;
    }
};