class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        unordered_map<string ,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string>ans;
        priority_queue<pair<int,string>>pq2;
        while(not pq.empty()){
            pq2.push({pq.top().first,pq.top().second});
            cout<<pq.top().first<<" ";
            pq.pop();
        }
        while(not pq2.empty()){
            ans.push_back(pq2.top().second);
            pq2.pop();
        }
        reverse(ans.begin(),ans.end());
        for(string ele:ans){
            cout<<ele<<" ";
        }
      
        return ans;
    }
};