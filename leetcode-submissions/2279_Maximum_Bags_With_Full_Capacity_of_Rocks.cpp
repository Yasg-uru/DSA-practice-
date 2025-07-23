class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>required(capacity.size(), 0 );
        for(int i=0;i<capacity.size();i++){
            required[i] = capacity[i]- rocks[i];
        }
        int count =0 ;
        sort(required.begin(), required.end());
        for(int i=0;i<required.size();i++){
            if(required[i]==0){
                count++;
            }else {
                if(additionalRocks>=required[i]){
                    count++;
                    additionalRocks-=required[i];
                }else{
                    break;
                }
            }
        }
        return count;
    }
};