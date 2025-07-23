class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int>s(arr.begin(),arr.end());
        int count =0 ;

        for(int i=1;i<=1000;i++){
            if(not s.count(i)){
                count++;
                if(count==k){
                    return i;
                }
            }    
        }
        return -1;
        
    }
};