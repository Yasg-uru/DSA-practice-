class Solution {
public:
    int n ;
    int result= INT_MAX ;
    void solve(vector<int>&cookies, int &k ,  vector<int>&children, int i){
        if(i>=n){
            int maxElement = *max_element(children.begin(), children.end());
            result = min(result , maxElement);
            return ;
        }
        int currentBag = cookies[i];
        // as we have a option to give a bag to the childrens 
        for(int j=0;j<k;j++){
            children[j]+=currentBag;
            solve(cookies, k, children , i+1);
            children[j]-=currentBag;
        }

    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>children(k,0);
        n= cookies.size();
        solve(cookies , k, children,0);
        return result ;

    }
};