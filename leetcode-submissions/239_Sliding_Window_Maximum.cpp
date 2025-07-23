class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>result;
        int i=0;
        int j =0 ;
        priority_queue<pair<int, int >>pq; // {element -> index } to check weather the range is valid or not 
        while(j<n){
            pq.push({nums[j], j});
            if(j-i+1==k){
                while(not pq.empty() and (pq.top().second<i or pq.top().second>j)){
                    pq.pop();
                }
                result.push_back(pq.top().first);
                i++;
            }
            j++;

        }
        return result ;

    }
};