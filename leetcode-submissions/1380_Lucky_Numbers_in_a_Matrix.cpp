class Solution {
public:

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
      unordered_map<int,int>mp;
      vector<int>ans;
      for(int i=0;i<matrix.size();i++){
      int mini=INT_MAX;
        for(int j=0;j<matrix[0].size();i++){
            mini=min(mini,matrix[i][j]);
        }
        mp[mini]++;

      }
    for(int i=0;i<matrix[0].size();i++){
      int maxi=INT_MIN;
        for(int j=0;j<matrix.size();i++){
            maxi=max(maxi,matrix[j][i]);
        }
        if(mp.find(maxi)!=mp.end()){
            ans.push_back(maxi);
        }

      }
      return ans;

    }
};