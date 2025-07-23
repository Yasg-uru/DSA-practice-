class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // we need to create a max heap and then apply operations on it by k times 
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        long long ans=0;
        //after this we need 
        while(k--){
            ans+=pq.top();
            double res=static_cast<double>(pq.top())/3;
            int temp=ceil(res);
            pq.pop();
            pq.push(temp);
        }
        return ans;
    }
};