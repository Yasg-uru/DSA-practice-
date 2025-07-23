class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans =0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                for(int k=j+1;k<arr.size();k++){
                    if((arr[i]+arr[k]+arr[j])==target){
                         ans ++;
                    }
                }
            }
        }
        return ans ;
    }
};