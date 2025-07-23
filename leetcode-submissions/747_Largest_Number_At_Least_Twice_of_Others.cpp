class Solution {
public:
int maxindex(vector<int>arr){
    int maxele=INT_MIN;
    int indexmax=0;
    for(int i=0;i<arr.size();i++){
       if(maxele<arr[i]){
           maxele=arr[i];
           indexmax=i;
       }
    }
    return indexmax;
}
    int dominantIndex(vector<int>& nums) {
        int maxeleindex=maxindex(nums);
        int element=nums[maxeleindex];
        nums.erase(nums.begin()+maxeleindex);
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            if((nums[i]*2)>element){
                flag=false;
                break;
            }


        }
        if(flag){
            return maxeleindex;
        }else
            return -1;
        
    }
};