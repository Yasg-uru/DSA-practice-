class Solution {
public:
int cnt=0;
bool canweplace(int row,int col,vector<vector<string>>&arr,int n){
    for(int i=0;i<n;i++){
        if(arr[i][col]=="Q"){
            return false;
        }
    }
    for(int j=0;j<n;j++){
        if(arr[row][j]=="Q"){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 and j>=0 ; i--,j--){
        if(arr[i][j]=="Q"){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 and j<n;i--,j++){
        if(arr[i][j]=="Q"){
            return false;
        }
    }
    return true;
}
void solve(int i,int n,vector<vector<string>>&arr){
    //base case
    if(i==n){
        cnt++;
        return;
    }
    //now checking for our places we can able to place our queen in which column

    for(int col=0;col<n;col++){
        if(canweplace(i,col,arr,n)){
            arr[i][col]="Q";
            solve(i+1,n,arr);
            arr[i][col]=".";


        }
    }
}
    int totalNQueens(int n) {
        vector<vector<string>>arr(n,vector<string>(n,"."));
        solve(0,n,arr);
        return cnt;
    }
};