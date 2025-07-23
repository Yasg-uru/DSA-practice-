class Solution {
public:
    int n ;
    int t[100001][2];
    int solve(string&s , int curr_index , int prevChar){
        if(curr_index>=n)return 0 ;
        if(t[curr_index][prevChar]!=-1) return t[curr_index][prevChar];
        int flip=INT_MAX;
        int not_flip= INT_MAX;
        if(s[curr_index]=='0'){
            if(prevChar==1){
                flip= 1+solve(s, curr_index+1, 1);
            }else{
                flip= 1+solve(s, curr_index+1, 1);
                not_flip= solve(s, curr_index+1, 0);
            }
        }else {
            // means current character is 1 
            if(prevChar==1){
              
                not_flip= solve(s, curr_index+1, 1);
            }else{
                flip = 1+solve(s, curr_index+1, 0);
                not_flip= solve(s, curr_index+1, 1);
            }
        }
        return t[curr_index][prevChar]=min(flip, not_flip);
    }
    int minFlipsMonoIncr(string s) {
        n = s.length();
        memset(t, -1 , sizeof(t));
        return solve(s, 0 , 0 );
    }
};