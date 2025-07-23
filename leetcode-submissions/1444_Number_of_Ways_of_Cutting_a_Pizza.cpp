class Solution {
public:
    int m , n ;
    int dp[55][55][15];
    long long  MOD = 1e9+7;
    int apples[55][55];
    int solve(int i , int j , int k){
        if(apples[i][j]<k){ // k log me batna tha but ab yaar apples hi nahi hai utne 
            return 0 ; 
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        // ek case or hai agar k==1 ho gaya but hamare paas 1 yaa usse jyada apples hone chahiye 
        if(k==1){
            return apples[i][j]>=1; // it returns then one way is found if it is true
        }
        int ans = 0;
        // ek baar horizontal cut karo 
        for(int h= i+1;h<m ;h++){
            // upar ka hissa or niche ka hissa nikaloge
            int lower_slice = apples[h][j];
            int upper_slice = apples[i][j]-lower_slice;
            if(upper_slice>=1 and lower_slice>=k-1){
                ans=(ans%MOD+solve(h, j , k-1)%MOD)%MOD;// ek apples baat diya
            }
        }
           // ek baar verticle cut karo 
        for(int v= j+1;v<n ;v++){
            // upar ka hissa or niche ka hissa nikaloge
            int right_slice = apples[i][v];
            int left_slice = apples[i][j]-right_slice;
            if(left_slice>=1 and right_slice>=k-1){
                ans=(ans%MOD +solve(i, v , k-1)%MOD)%MOD;// ek apples baat diya
            }
        }
        return dp[i][j][k]= ans ;

    }
    int ways(vector<string>& pizza, int k) {
        m= pizza.size();
        n= pizza[0].size();
        memset(apples, 0 , sizeof(apples));
        memset(dp, -1, sizeof(dp));
        //ab iske baad na isko fill karo reverse order me 
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                //ab na ham previous ka result add kardenge 
                apples[i][j]=apples[i][j+1]; // jaise ki apne ko pata hi hai ki previous me kitne apples hai to ab is row ke bache hue apples bhi add kar denge 
                for(int l =i;l<m;l++){
                    if(pizza[l][j]=='A') apples[i][j]++;
                }
            }
        }
        // ab apple bharne ke baad ab cuts banake dekhenge 
        return solve(0 , 0 , k); // start karenenge 

    }
};