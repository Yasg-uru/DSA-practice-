class Solution {
public:
    int t[5001][10];
     int solve(int n , int cell,unordered_map<int, vector<int>>&adj){
        if(n==0){
            return 1; // one path is found
        }
        if(t[n][cell]!=-1){
            return t[n][cell];
        }
        int result = 0 ;

        for(auto &nextCell : adj[cell]){
            result +=solve(n-1,nextCell, adj );
        }
        return t[n][cell]= result;
     }
    int knightDialer(int n) {
        int result = 0 ;
         unordered_map<int, vector<int>>mp;
     mp[0]= {4, 6};
     mp[1]= {6,8};
     mp[2]={9,7};
     mp[3]={8, 4};
     mp[4]={9, 0,3};
     mp[5]={};
     mp[6]={7, 1,0};
     mp[7]={6,2};
     mp[8]={3, 1};
     mp[9]={2, 4}   ;
     memset(t, -1 , sizeof(t));
        for(int cell = 0 ;cell<=9;cell++){
            result+=solve(n-1, cell, mp);// first answer is added thats why we substracted by one 
        }
        return result;
    }
};