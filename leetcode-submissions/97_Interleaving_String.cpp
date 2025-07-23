class Solution {
public:
    int t[101][101][101];
    bool solve(int i,int j,int k,string s1,string s2,string s3){
        int m=s1.size(),n=s2.size(),N=s3.size();
        //base case 
        if(i==m and j==n  and k==N) return true ;
        if(k>=N) return false ;
        bool result =false ;
        if(t[i][j][k]!=-1) return t[i][j][k];
        if(s1[i]==s3[k]){
            result =solve(i+1,j,k+1,s1,s2,s3);
        }
        if(s2[j]==s3[k]){
            result =solve(i,j+1,k+1,s1,s2,s3);
        }
    return t[i][j][k]=result;

    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(t,-1,sizeof(t));
        return solve(0,0,0,s1,s2,s3);

    }
};