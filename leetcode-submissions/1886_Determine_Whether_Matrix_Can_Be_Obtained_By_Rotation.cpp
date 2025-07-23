class Solution {
public:
    int m , n ;

    void Rotate(vector<vector<int>>&g){
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(g[i][j], g[j][i]);
            }
        }
        for(int i=0;i<m;i++){
            reverse(g[i].begin(), g[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& g, vector<vector<int>>& target) {
         m = g.size();
        n = g[0].size();
        for(int dir=0 ;dir<4;dir++){
            Rotate(g);
            if(g==target){
                return true ;
            }
        }
      return false;
    }
};