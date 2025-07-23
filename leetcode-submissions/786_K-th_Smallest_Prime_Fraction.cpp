class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        //now i am creating the min heap of the <double,pair<int,int>>
        //now initializing the min heap by usinght egreater int method 
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<>>pq;
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
            }
        }
        vector<int>ans(2);

        for(int i=0;i<k;i++){
ans[0]=pq.top().second.first;
ans[1]=pq.top().second.second;
pq.pop();

        }
        return ans;
    }
};