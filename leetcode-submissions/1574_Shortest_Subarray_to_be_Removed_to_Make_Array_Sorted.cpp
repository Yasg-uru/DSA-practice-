class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;
        while(j>0 and arr[j]>=arr[j-1]){
            j--;
        }
        int ans=j;
        while(i<j and (i==0 or arr[i-1]<=arr[i])){
            while(j<n and arr[i]>arr[j]){
                j++;
            }
            ans=min(ans,j-i-1);
            i++;
        }
return ans;
    }
};