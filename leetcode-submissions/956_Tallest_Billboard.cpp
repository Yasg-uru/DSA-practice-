class Solution {
public:
    int n ;

    int solve(int i , int l1 , int l2 , vector<int>&rods){
        if(i>=n) return l1==l2?l1:0;
        int add_l1= solve(i+1, l1+rods[i], l2, rods);
        int add_l2=  solve(i+1, l1, l2+rods[i], rods);
        int skipped= solve(i+1, l1, l2, rods);

        return max(max(add_l1, add_l2), skipped);
    }
    int tallestBillboard(vector<int>& rods) {
        n= rods.size();
        return solve(0, 0 , 0 , rods);

    }
};