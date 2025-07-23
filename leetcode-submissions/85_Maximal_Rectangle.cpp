class Solution {
public:
int area=0;
int findlargestrectangle(int n,vector<int>&histogram){
for(int i=0;i<n;i++){
    int breadth=1;
    area=max(area,histogram[i]);
    for(int j=i-1;j>=0;j--){
        if(histogram[j]>=histogram[i]){
            breadth++;
        }else{
            break;
        }
    }
    for(int j=i+1;j<n;j++){
        if(histogram[j]>=histogram[i]){
            breadth++;
        }else{
            break;
        }
    }
    area=max(area,histogram[i]*breadth);
}
return area;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        //now i am trying this question by uisng the water trapping approach
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>rowHistogram(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    rowHistogram[j]++;
                    //increasing the frequency of that columnn
                }else{
                    rowHistogram[j]=0;
                }
            }
            area=max(area,findlargestrectangle(m,rowHistogram));

        }
        return area;
    }
};