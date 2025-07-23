class Solution {
public:
    int t[51][51];
    int solve(vector<int>&values , int i , int j ){
        if(j-i<2){
            return 0; // because their is not k variable is formed 
            
        }
        if(t[i][j]!=-1){
return t[i][j];}
        int ans = INT_MAX;
        for(int k = i+1;k<j;k++){
            int sum = solve(values , i, k)+solve(values ,k , j)+(values[i]*values[j]*values[k]);
            ans = min(ans , sum);
        }
        return t[i][j]= ans ;
        
    }
    int minScoreTriangulation(vector<int>& values) {
       memset(t, -1 , sizeof(t));
        int n = values.size();
        return solve(values , 0 ,n-1 );
    }
};