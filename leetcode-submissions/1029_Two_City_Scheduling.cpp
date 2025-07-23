class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto& a , auto&b){
            return (a[0]-a[1])<(b[0]-b[1]);
        });
        int n = costs.size()/2;
        int total =0;
        for(int i =0 ;i<n;i++) total+=costs[i][0];
        for(int i= n;i<2*n;i++) total+=costs[i][1];
        return total;
            
    }
};