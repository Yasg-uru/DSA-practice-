class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       multiset<int,greater<int>>m;
       int left=0,right=0;
int maxans=INT_MIN;

while(right<nums.size()){
    m.insert(nums[right]);
    int largest=*m.begin();
    int smallest=*m.rbegin();
    while(abs(largest-smallest)>limit){
        m.erase(m.find(nums[left]));
        left++;
        largest=*m.begin();
        smallest=*m.rbegin();

    }
    maxans=max(maxans,right-left+1);
    right++;

}
return maxans;
    }
};