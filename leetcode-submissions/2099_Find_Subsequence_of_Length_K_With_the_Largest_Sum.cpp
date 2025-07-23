class Solution {
public:
    static bool cmp(pair<int, int >&a , pair<int , int >&b){
        return a.second<b.second ;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int , int >>pq;
        for(int i =0 ;i<nums.size();i++){
            pq.push({nums[i], i });
        }
        vector<pair<int , int>>pairs;
        while(not pq.empty() and k>0){
          pairs.push_back(pq.top());
           pq.pop();
           k--;
        }
        sort(begin(pairs), end(pairs), cmp);
        vector<int>ans;
        for(auto& pair : pairs){
            ans.push_back(pair.first);
        }
        return ans ;
        
    }
};