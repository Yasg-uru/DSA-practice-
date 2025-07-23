class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int , int>r , l;
        int n = nums.size();
        int result  = 0 ;
        for(int i =0 ;i<n;i++){
            r[nums[i]]++;
        }
        for(int j =0 ;j<n;j++){
            r[nums[j]]--;
            int t = nums[j]*2;
            int Left = l[t];
            int Right = r[t];
            result+=(Left*Right);
            l[nums[j]]++;
        }
        
        return result ;
    }
};