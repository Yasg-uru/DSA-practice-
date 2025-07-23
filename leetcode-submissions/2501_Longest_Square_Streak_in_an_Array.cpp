class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
     // we need to maximize the streak length after sorting the array 
     sort(nums.begin(),nums.end());
     //after that we need to create a map for storing an element with their streak 
     unordered_map<int,int>mp;
     int maxStreak=0;
     for(int i=0;i<nums.size();i++){
        int root=(int)sqrt(nums[i]);
        if( root*root==nums[i] and mp.find(root)!=mp.end()){
            //then sqrt is present then we need to add 
            mp[nums[i]]=mp[root]+1;
            
        }else{

            mp[nums[i]]=1;
        }

        maxStreak=max(maxStreak,mp[nums[i]]);
     }   
     //after finding the streaks 
    
     return maxStreak<2?-1:maxStreak;
    }
};