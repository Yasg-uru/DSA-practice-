class Solution {
public:
static bool cmp(const int &a,const int &b){
    return to_string(a)<to_string(b);
}
    int findKthNumber(int n, int k) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        sort(arr.begin(),arr.end(),cmp);
        //after sorting the array in ascending order we need 
return arr[k-1];
        
    }
};