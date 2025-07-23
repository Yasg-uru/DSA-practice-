#include <string>
#include <vector>

class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char,int>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    priority_queue<pair<int,char>>pq;
    for(auto ele:mp){
        pq.push({ele.second,ele.first});
    }
    string ans="";
    while(!pq.empty()){
        int cnt=pq.top().first;
        while(cnt){
            ans+=pq.top().second;
            cnt--;
        }
        pq.pop();
    }
    return ans;
    }
};
