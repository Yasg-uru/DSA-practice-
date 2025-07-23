class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      vector<vector<int>>directions={{1, 0}, {-1,0}, {0, 1}, {0 , -1}};
      int m = image.size(), n  = image[0].size();
      queue<pair<int , int >>q;
      q.push({sr, sc});
      while(not q.empty()){
        int i= q.front().first ;
        int j = q.front().second ;
        q.pop();
        for(auto& dir : directions){
            int i_ = dir[0]+i;
            int j_ = dir[1]+j;
            if(i_>=0 and j_>=0 and i_<m and  j_<n and image[i_][j_]!=0 and image[i_][j_]!=color){
                q.push({i_, j_});
                image[i_][j_]= color;
            }
        }
      }
      return image;
    }
};