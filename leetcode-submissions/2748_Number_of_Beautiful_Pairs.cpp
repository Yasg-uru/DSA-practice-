class Solution {
public:
    int extractFirstDigit(int number ){
        string str=std::to_string(number);
        return str[0]-'0';
    }
    int extractLastDigit(int number ){
        string str=std::to_string(number);
        return str.back()-'0';
    }
    int countBeautifulPairs(vector<int>& nums) {
        int pairs=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
               int firstDigit=extractFirstDigit(nums[i]);
               int lastDigit=extractLastDigit(nums[j]);
               if(std::gcd(firstDigit,lastDigit)==1){
                pairs++;
                
               }
            }
        }
        return pairs;
    }
};