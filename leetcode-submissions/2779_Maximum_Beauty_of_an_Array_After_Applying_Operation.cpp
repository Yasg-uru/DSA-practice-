class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // we need to calculate the particular range values 
        vector<pair<int,int>>intervals;
        for(int i=0;i<nums.size();i++){
            intervals.push_back({nums[i]-k,nums[i]+k});
        }
        //after this we need to find out the maximum overlapping intervals 
        deque<pair<int,int>>dq;
        sort(intervals.begin(),intervals.end());
        int result =1;
        
        // we have maximun one overlapping intervals 
        for(int i=0;i<intervals.size();i++){
            while (not dq.empty() and dq.front().second<intervals[i].first){
                dq.pop_front();

            }
            dq.push_back(intervals[i]);
            result=max(result ,(int)dq.size());
        }
        return result ;
    }
};