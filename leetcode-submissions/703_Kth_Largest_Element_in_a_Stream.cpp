class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>>pq;

int cnt;
int size;
    KthLargest(int k, vector<int>& nums) {
        cnt=k;
        for(int ele:nums){
            pq.push(ele);
        }
        size=nums.size();
    }
    
    int add(int val) {
       pq.push(val);
       
       priority_queue<int>pqtemp;
       while(pq.size()>cnt){
           pqtemp.push(pq.top());
           pq.pop();

       }
       int ans=pq.top();
       while(not pqtemp.empty()){
           pq.push(pqtemp.top());
           pqtemp.pop();
       }
       if(pq.size()>size){
           pq.pop();
       } 
       return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */