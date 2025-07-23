class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n  =arr.size();
        int maxEle = INT_MIN ;
        int maxEleIndex = -1;
        for(int i =0 ;i<n;i++){
            if(maxEle<arr[i]){
                maxEle = arr[i] ;
                maxEleIndex  = i;
            }
        }
        // after find the maxElement we need to start traversing from their forward as well as backward 
        bool isLeftEntered = false, isRightEntered = false;
        for(int i = maxEleIndex;i>=1;i--){
            isLeftEntered= true;
            if(arr[i-1]>=arr[i]){
                return false;
            }
        }
        for(int i = maxEleIndex;i<n-1;i++){
            isRightEntered= true ;
            if(arr[i+1]>=arr[i]){
                return false;
            }
        }
        
        return isRightEntered and isLeftEntered;
    }
    
};