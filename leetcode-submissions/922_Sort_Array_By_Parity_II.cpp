class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>even , odd ;
        for(int num : nums){
if(num%2){
    odd.push_back(num);
}else{
    even.push_back(num);
}
        }
        int l =0 , r = 0 ;
        int n = nums.size();
        vector<int>ans(n );
        for(int i =0 ;i<n;i++){
            if(i%2){
                ans[i]= odd[r++];
            }else{
            ans[i]= even[l++];
            }
        }
        return ans ;
    }
};