class Solution {
public:
    
    vector<vector<double>>t;

    double solve(int A , int B){
        if( t[A][B]!=-1) return  t[A][B];
        if(A==0 and B==0) {
            return 0.5; // we have to return half 
        }
        if(A==0) {
            return 1.0; //because we haave a probability of a is full 

        }
        if(B==0) return 0.0 ;
        // we have four options to serve the soup
        return t[A][B]= 0.25 * (
            solve(max(0, A - 100), B) +
            solve(max(0, A - 75), max(0, B - 25)) +
            solve(max(0, A - 50), max(0, B - 50)) +
            solve(max(0, A - 25), max(0, B - 75))
        );
    }
    double soupServings(int n) {
        if(n>5000) return 1.0;

        t.clear();
        t.resize(n+1, vector<double>(n+1, -1.0));

        return solve(n , n );

    }
};