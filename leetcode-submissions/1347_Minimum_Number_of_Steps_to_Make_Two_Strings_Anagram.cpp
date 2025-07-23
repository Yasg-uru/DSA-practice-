class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char , int >mp1 , mp2;
        for(char ch : s) mp1[ch]++;
        for(char ch : t) mp2[ch]++;
        int ans =0 ;
        for(auto& ele : mp1){
            int required = max(ele.second - mp2[ele.first], 0);
            ans+=required;
            
        }
        return ans ;
    }
};