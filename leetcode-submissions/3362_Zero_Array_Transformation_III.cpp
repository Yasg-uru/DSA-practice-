class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int Q = queries.size(); 
        int n = nums.size();
        int j =0 , usedQueries =0 ;
        priority_queue<int>maxHeap ;
        priority_queue<int , vector<int>, greater<int>>pastUsedEndings ;
        sort(queries.begin(), queries.end());
        for(int i =0 ;i<n;i++){
            while(j<Q and  queries[j][0]==i){
                //jo queries is current ith ko impact kar sakta hai usse rakhlo 
                maxHeap.push(queries[j][1]);
                j++;

            }
            // ab kya karna hai ab ye dekhna hai ki past me koi query already pada hai toh usse use karo instead of using the new query 
            nums[i]-=pastUsedEndings.size();
            // ab ye dekho ki agar phir bhi zero nahi hua toh max heap ke ending use karke dekho 
            while(nums[i]>0 and not maxHeap.empty() and maxHeap.top()>=i){
                pastUsedEndings.push(maxHeap.top());
                maxHeap.pop();
                usedQueries++;
                //ek new query use kar liya or future ke liye daba ke rakh loya 
                nums[i]--;
                // nums ko decrement kar liya
            }
            if(nums[i]>0){
                return -1; //ab koi aisa query nahi bacha jo kuchh impact karien iss nums[i ] kek liye 
            }
            while(not pastUsedEndings.empty() and pastUsedEndings.top()<=i){
                //purani endings jo future me koi kaam nahi aane wali unko hatao 
                pastUsedEndings.pop();
            }
        }
        return Q-usedQueries;
    }
};