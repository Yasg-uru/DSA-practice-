class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
int result=0;
for(int j=queries[i][0];j<=queries[i][1];j++){
result=result^arr[j];
}
ans.push_back(result);
        }
        return ans;
    }
};