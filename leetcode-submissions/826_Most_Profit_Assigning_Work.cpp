class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // i am solving this question by using the greedy approach 
        //sorting the pair of the profit and difficuly in the ascending order
        vector<pair<int,int>>temp;
        for(int i=0;i<worker.size();i++)
        {
            temp.push_back({difficulty[i],profit[i]});
        }
        sort(temp.begin(),temp.end());
        sort(worker.begin(),worker.end());
        int j=0;
        int res=0;
        int best=0;

        for(auto work:worker){
            while(work>=temp[j].first and j<worker.size()){
                best=max(best,temp[j++].second);
            }
            res+=best;
        }
        return res;
    }
};