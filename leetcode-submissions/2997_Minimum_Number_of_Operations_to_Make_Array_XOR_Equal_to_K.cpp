class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
int finalxor=0;
for(int i=0;i<nums.size();i++){
    finalxor=finalxor^nums[i];

}
int count =0;
while(k>0 or finalxor>0){
    if(k%2!=finalxor%2){
        count ++;
    }
    k/=2;
    finalxor/=2;

}
return count ;
    }
};