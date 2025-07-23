class Solution {
public:

//creating custom comaprator
static bool customcmp(const int &a,const int &b){
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),customcmp);
        string result;
        for(int ele:nums){
            result+=to_string(ele);
        }
        return result;
    }
};