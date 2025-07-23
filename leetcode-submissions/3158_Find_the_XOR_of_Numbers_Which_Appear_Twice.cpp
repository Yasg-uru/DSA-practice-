class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int , int >mp;
        int firstNumber =0 ;
        int secondNumber =0 ;
        for(int&  n :nums){
            mp[n]++;
            
        }
        for(auto& ele : mp){
            if(firstNumber==0 and ele.second==2){
                firstNumber = ele.first ;
            }
            
             else if(secondNumber==0 and ele.second==2){
                secondNumber = ele.first;
            }
        }
        if((firstNumber==0 and secondNumber==0) or (firstNumber==secondNumber)){
            return 0 ;

        }
        return firstNumber^secondNumber ;


    }
};