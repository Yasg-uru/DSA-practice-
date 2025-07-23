class Solution {
public:
    int n ;
    int t[101][201];
    long long solve(string &s, int &k , int count, int i   ){
        if(i>=n){
            return INT_MAX;
        }
        if(t[i][count]!=-1)
        {
            return t[i][count];
        }
        if(count==k){
            return 0 ;

        }
        long long  take = INT_MAX;
        long long  not_take = INT_MAX ;

        if(s[i]=='W'){
            take = 1+solve(s, k , count+1, i+1);
            not_take = solve(s, k , 0 , i+1);//resetting count to zero 
        }else{
            not_take =  solve(s, k ,count+1 , i+1);
        }
        return t[i][count]= min(take , not_take);
    }
    int minimumRecolors(string blocks, int k) {
         n = blocks.size();
         memset(t, -1 , sizeof(t));
        return solve(blocks , k , 0 , 0 );
    }
};