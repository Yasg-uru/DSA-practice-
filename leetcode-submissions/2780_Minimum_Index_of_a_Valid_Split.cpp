class Solution {
public:
    
    int minimumIndex(vector<int>& nums) {
     unordered_map<int , int>firstMap , secondMap;
     for(int& num : nums){
        secondMap[num]++;
     }
     int n = nums.size();
     for(int i=0;i<n;i++){
        int num = nums[i];
        firstMap[num]++;
        secondMap[num]--;
        if(firstMap[num]*2>i+1 and secondMap[num]*2>n-i-1){
            return i;
        }
     }
     return -1;

        
    }
};