class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char , int >mp;
        for(char ch : s){
            mp[ch]++;
        }
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto& ele : mp){
            pq.push(ele.second);
        }
        int ans =0 ;
        while(pq.size()>k and not pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans ;
    }
};