class Solution {
public:
    bool isPossible(int x,vector<int>quantities,int n){
        for(int &products:quantities){
            int div=(products + x - 1) / x;
            n-=div;
            if(n<0){
                return false;
            }
        }
        return true ;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int r=*max_element(begin(quantities),end(quantities));
        int l=1;
        int result=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(mid,quantities,n)){
                result=mid;
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        return result;
    }
};