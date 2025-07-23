class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int n = 1 , cnt =0 ,  sum =0 ;
        unordered_set<int>s(nums.begin(), nums.end());

        while(true){
            if(not s.count(n)){
                cnt++;
                sum+= n;
                if(cnt==k){
                    break;
                }
            }
            n++;
        }
        
        return sum ;
    }
};