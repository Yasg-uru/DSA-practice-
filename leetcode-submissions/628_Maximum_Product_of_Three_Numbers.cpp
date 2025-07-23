class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int>pq;
        for(int ele:nums){
            pq.push(ele);
        }
        int count=3;
        int product=1;
        while(count--){
            product*=pq.top();
            pq.pop();
        }
        return product;
    }
};