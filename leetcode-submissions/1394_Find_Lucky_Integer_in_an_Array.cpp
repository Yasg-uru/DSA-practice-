class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>frequency;
        for(int ele:arr){
            frequency[ele]++;
        }
        int ans=-1;
        for(auto ele:frequency){
            if(ele.first==ele.second){
                ans=max(ele.first,ans);
            }
        }
        return ans;
    }
};