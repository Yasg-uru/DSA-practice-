class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans =0;
        for(int i=0;i<hours.size();i++){
            for(int j=i+1;j<hours.size();j++){
                if((hours[i]+hours[j])%24==0){
                    ans++;
                }
            }
        }
        return ans ;
    }
};