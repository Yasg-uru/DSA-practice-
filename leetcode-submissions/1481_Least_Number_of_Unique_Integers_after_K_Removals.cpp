class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
       
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       unordered_map<int,int>mp;
       for(int i=0;i<arr.size();i++){
           mp[arr[i]]++;
           

       }
       for(auto ele:mp){
           pq.push({ele.second,ele.first});
       }
       while(k--){
           int element=pq.top().second;
           mp[element]--;
           if(mp[element]==0){
               mp.erase(element);
           }
           pq.pop();
       }
       return mp.size();
       
    }
};