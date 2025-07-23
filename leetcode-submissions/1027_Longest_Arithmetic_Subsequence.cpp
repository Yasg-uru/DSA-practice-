class Solution {
public:
    int n ;
    unordered_map<int, int >mp;

    int solve(int i , int &d, vector<int>& nums){
        if(i<0) return 0 ;
        int maxAns = 0 ;
        int key = i*1000+d;
        if(mp.find(key)!=mp.end()) return mp[key];

        
        for(int k=i-1;k>=0;k--){
            if((nums[i]-nums[k])==d){
                maxAns = max(maxAns , 1+solve(k, d, nums));
            }
        }
        return mp[key]=maxAns;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int maxAns = 0;
        mp.clear();
        n= nums.size();
      
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n ;j++){
                int d = nums[j]-nums[i];
                maxAns = max(maxAns , 2+solve(i,d, nums));
            }
        }
        return maxAns ;
    }
};