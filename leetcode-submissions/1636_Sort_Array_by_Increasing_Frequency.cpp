class Solution {
public:
 static bool cmp(const pair<int,int>& a ,pair<int,int>&b){
    if(a.second==b.second ){
        return a.first<b.first;
    }
    return a.second>b.second;
}

    vector<int> frequencySort(vector<int>& nums) {
        //we need to create map and iterate on it and then sorting the vector pair of that 
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
       }
        
        //after that we need to create an vector of pair and then sort it using the custom comparator
        vector<pair<int,int>>arr;
        for(auto ele:mp){
            arr.push_back(ele);

        }
        sort(arr.begin(),arr.end(),cmp);
        vector<int>ans;
        for(auto ele:arr){
            int cnt=ele.second;
            while(cnt--){
                ans.push_back(ele.first);
            }
        }
        reverse(ans.begin(),ans.end());
return ans;
    }
};