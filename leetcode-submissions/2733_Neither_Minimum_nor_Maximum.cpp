class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int maxele=INT_MIN;
        for(int ele:nums){
            maxele=max(ele,maxele);
        }
        int minele=INT_MAX;
        for(int ele:nums){
            minele=min(minele,ele);
        }
        int nmnm=-1;
        for(int ele:nums){
            if(maxele>ele and ele>minele){
                nmnm=ele;
                break;
            }
        }
        return nmnm;
    }
};