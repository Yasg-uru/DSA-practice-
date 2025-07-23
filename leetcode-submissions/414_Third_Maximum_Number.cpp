class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return nums[1];
        }
        unordered_set<int>s;
        for(int ele:nums){
            s.insert(ele);
        }
        priority_queue<int>pq;
        for(auto ele:s){
            pq.push(ele);
        }
        int i=1;
        while(i<=2){
            i++;
            pq.pop();
        }
return pq.top();
    }
};