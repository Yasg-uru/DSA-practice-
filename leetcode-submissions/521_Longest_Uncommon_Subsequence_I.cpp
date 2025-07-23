class Solution {
public:
int lucs(string a,string b,int m,int n){

    if(m<0 or n<0){
        return 0;
    }
    if(a[m]!=b[n]){
        return 1+lucs(a,b,m-1,n-1);
    }else{
        return max(lucs(a,b,m-1,n),lucs(a,b,m,n-1));
    }
}
    int findLUSlength(string a, string b) {
        if(a==b){
            return -1;
        }
       int m=a.size()-1;
       int n=b.size()-1;
       return lucs(a,b,m,n); 
    }
};