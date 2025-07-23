class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int , int >mp;
        int count =0;

        for(int& num : nums ){
            if(mp.find(k-num)!=mp.end()){
                count++;
                mp.erase(k-num);
                nums.erase(remove(nums.begin(), nums.end(), num), nums.end());
                nums.erase(remove(nums.begin(), nums.end(), k-num), nums.end());
                continue;
            }
            
                mp[num]++;
            
        }
        return count ;
    }
};