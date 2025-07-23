class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int count=0;
                if(nums[i]==nums[j]){
                    count++;
                    if(count>2){
                        continue;
                    }
                }
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};