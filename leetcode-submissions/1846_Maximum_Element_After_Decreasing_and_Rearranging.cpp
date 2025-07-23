class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int currMax = arr[0];
        sort(arr.begin(), arr.end());
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])>1){
                arr[i]= arr[i-1]+1;
            }
                currMax= arr[i];
        }
        return currMax ;
    }
};