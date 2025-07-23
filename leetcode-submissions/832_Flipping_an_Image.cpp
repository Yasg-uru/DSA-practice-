class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(vector<int>&vec : image){
            reverse(vec.begin(), vec.end());
        }
        for(int i =0 ;i<image.size();i++){
            for(int j =0 ;j<image[0].size();j++){
                image[i][j] = not image[i][j];
            }
        }
        return image ;
    }
};