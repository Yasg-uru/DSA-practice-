class Solution {
public:
    typedef pair<int,int> p;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto curr=pq.top();
            pq.pop();
            pq.push({curr.first*multiplier,curr.second});
        }
        vector<int>ans(nums.size()) ;
        while(not pq.empty()){
            int index=pq.top().second ;
            int element =pq.top().first;

ans[index]=element ;
pq.pop();
        }
        return ans ;
    }
};