class Solution {
public:
    string triangleType(vector<int>& nums) {
        unordered_map<int , int >mp;
        for(int n : nums) mp[n]++;
        if(mp.size()==3){
            return "scalene";
        }else if(mp.size()==2){
            return "isosceles";
        }
        return "equilateral";
    }
};