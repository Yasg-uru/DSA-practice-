class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
                if(sum==target){
                   return sum;
                }else if(sum<target){
                    pq.push(sum);
                    j++;
                }else{
                    pq.push(sum);
                    k--;
                }
            }
        }
        while(pq.top()<0){
            pq.pop();
        }
        if(not pq.empty()){

        return pq.top();
        }else{
            return 0;
        }
    }
};