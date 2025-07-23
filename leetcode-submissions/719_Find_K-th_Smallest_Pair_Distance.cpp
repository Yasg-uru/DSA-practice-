class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // for finding the smallest distance pair  then sorting the array in ascending order 
        sort(nums.begin(),nums.end());
      
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size()-1;i++){
            pq.push(abs(nums[i]-nums[i+1]));
            //after that we need to find the 
        }
        k=k-1;
        while(k--){
            pq.pop();
        }
        return pq.top();

    }

};