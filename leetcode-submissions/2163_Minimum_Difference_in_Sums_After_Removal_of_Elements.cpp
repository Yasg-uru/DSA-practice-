class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long  N = nums.size();
        long long  n = N/3;
        vector<long long >leftMinSum(N, 0 ), rightMaxSum(N , 0);
        long long leftSum =0 , rightSum =0 ;
        priority_queue<int>maxHeap;
        priority_queue<int, vector<int>, greater<int>>minHeap;
        for(int i =0 ;i<2*n;i++){
            leftSum+=nums[i];
            maxHeap.push(nums[i]);
            if(maxHeap.size()>n){
                leftSum-=maxHeap.top();
                maxHeap.pop();
            }
            leftMinSum[i] = leftSum;
        }

        for(int i = N-1;i>=n;i--){
            minHeap.push(nums[i]);
            rightSum +=nums[i];
            if(minHeap.size()>n)
            {
                rightSum-=minHeap.top();
                minHeap.pop();
            }
            rightMaxSum[i]=rightSum;
        }
        long long  minAns = LLONG_MAX;
        for(int i =n-1 ;i<2*n;i++){
            minAns = min(minAns , leftMinSum[i]-rightMaxSum[i+1]);
        }
        return minAns ;
        
    }
};