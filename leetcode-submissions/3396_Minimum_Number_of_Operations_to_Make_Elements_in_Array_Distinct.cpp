class Solution {
public:
    bool isArrayContainsDistinct(vector<int>&nums , int start){
        unordered_map<int , int >mp;

        for(int i=start;i<nums.size();i++){
            if(mp[nums[i]]>=1){
                return false;
            }
            mp[nums[i]]++;
        }
        return true ;
    }
    int minimumOperations(vector<int>& nums) {
       int i=0;
       const int n = nums.size();
       int operations =0;

       while(i<n){
        if((n-i)>=3 and isArrayContainsDistinct(nums , i)==false){
            i+=3;
            
            operations++;
            
        }else if((n-i)<3 and isArrayContainsDistinct(nums , i)==false){
            operations++;
            break;
        }else{
            i++;
        }

      
        

       }
       return operations ;

    }
};