class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
       //now solving this question by using the simple approach  we need to calculate the ratio of the wage/quality and storing it on a pair of the quality 
       
       vector<pair<double,int>>ratio;
       int sum=0;
       double result=INT_MAX;
       for(int i=0;i<quality.size();i++){
        ratio.push_back({(double)wage[i]/quality[i],quality[i]});
       }
       //sorting the ratio array in ascending order
       sort(ratio.begin(),ratio.end());
       //now declaring the priority queue
       priority_queue<int>pq;
       for(int i=0;i<ratio.size();i++){
        sum+=ratio[i].second;
        pq.push(ratio[i].second);
        if(pq.size()>k){
            sum-=pq.top();
            pq.pop();
        }
        if(pq.size()==k){
            result=min(result,sum*ratio[i].first);

        }
       }
       return result;


    }
};