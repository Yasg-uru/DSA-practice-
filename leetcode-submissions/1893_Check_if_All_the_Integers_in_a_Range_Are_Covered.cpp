class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool>covered(51 , false);
        for(vector<int>range : ranges){
            for(int i =range[0] ;i<=range[1];i++){
                covered[i] = true ;
            }
        }
        for(int i= left ; i<=right ;i++){
            if(not covered[i]){
                return false;
            }
        }
        return true ;
    }
};