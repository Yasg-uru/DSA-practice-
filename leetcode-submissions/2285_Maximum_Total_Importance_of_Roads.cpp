class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //now calculating the indegree of the nodes and after that sorting the indegree and multiplying by the numbers 
        vector<int>indegree(n);
        for(int i=0;i<roads.size();i++){
            indegree[roads[i][0]]++;
              indegree[roads[i][1]]++;
        }
        //after calculating indegree sorting them 
        sort(indegree.begin(),indegree.end());
        //after that assining numbers to its element 
        long long ans =0;
        for(int i=1;i<=n;i++){
            ans+=(indegree[i-1]*i);
        }
        return ans;
    }
};