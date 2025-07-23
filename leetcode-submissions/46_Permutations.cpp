class Solution {
public:
vector<vector<int>>ans;
void recursive(vector<int> num,int i){
    if(i==num.size()){
        ans.push_back(num);
        return;
    }
    for(int j=i;j<num.size();j++){
        swap(num[i],num[j]);
        recursive(num,i+1);
        swap(num[i],num[j]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        recursive(nums,0);
        return ans;
    }
};