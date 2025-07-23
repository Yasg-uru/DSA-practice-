class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int target = totalSum/3;
        int currSum =0 , count =0;
        for(int i =0 ;i<arr.size();i++){
            currSum+=arr[i];
            if(currSum==target){
                currSum =0 ;
                count++;
                if(count==2 and i<arr.size()){
                    return true ;
                }
            }

        }
        return false;
    }
};