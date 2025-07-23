class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minOperations = 0 ;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int & num :nums){
            pq.push(num);
        }
        while(pq.top()<k){
            minOperations++;
            int firstEle= pq.top();
            pq.pop();
            int secondEle = pq.top();
            pq.pop();
            int val= min(firstEle, secondEle) * 2 + max(firstEle , secondEle);
            pq.push(val);
        }
        return minOperations ;
    }
};