class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        //brute force 
        int n = arr.size();
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            for(int j =0;j<i;j++){
                if(arr[j]<=arr[i]){
                    ans[i]= max(ans[i], ans[j]+1);
                }
            }
        }
        return ans ;

    }
};