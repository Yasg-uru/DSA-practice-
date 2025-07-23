class Solution {
public:
    int calculate_swaps(vector<int>&odds , vector<int>&valid_odd_positions){
        int swaps =0 ;
        for(int i =0;i<odds.size();i++){
         swaps+=abs(odds[i]-valid_odd_positions[i]);   
        }
        return swaps ;
    }
    int minSwaps(vector<int>& nums) {
vector<int>odds , evens;
        int n= nums.size() ; 
        for(int i =0 ;i<n;i++){
            if(nums[i]%2==1){
                odds.push_back(i);
            }else{
                evens.push_back(i);
            }
            
        
        }

        int evens_length = evens.size(), odds_length= odds.size();
        if(n%2==0){
            if(evens_length!=odds_length){
                return -1;
            }
        }else {
            if(abs(evens_length-odds_length)>1){
                return -1;
            }
        }
        int minSwaps = INT_MAX;
        if(odds_length>=evens_length){
            vector<int>valid_odd_positions ;
            for(int i =0 ;i<n;i+=2){
                valid_odd_positions.push_back(i);
            }
            int required_swaps = calculate_swaps(odds ,valid_odd_positions );
            minSwaps = min(minSwaps , required_swaps);
        }
        if(evens_length>=odds_length){
            vector<int>valid_odd_positions ;
            for(int i =1 ;i<n;i+=2){
                valid_odd_positions.push_back(i);
            }
            int required_swaps = calculate_swaps(odds ,valid_odd_positions );
            minSwaps = min(minSwaps , required_swaps);
        }
        return (minSwaps==INT_MAX)?-1:minSwaps;
    }
};