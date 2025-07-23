class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // we need to iterate through the nested loop 
        vector<int>ans(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            int mostBeauty=INT_MIN;
            for(int j=0;j<items.size();j++){
                if(items[j][0]<=queries[i]){
                    mostBeauty=max(mostBeauty,items[j][1]);
                }
            }
            ans[i]=(mostBeauty==INT_MIN?0:mostBeauty);
        }
        return ans;
    }
};