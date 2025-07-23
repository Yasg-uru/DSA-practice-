class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        set<int>s1;
        set<int>s2;
        for(int i=0;i<nums.size();i++){
            if(s1.find(nums[i])==s1.end()){
                s1.insert(nums[1]);
                
            }else if(s2.find(nums[i])==s2.end()){
                s2.insert(nums[i]);
            }else{
                return false;
            }
        }
        return (s1.size()==s2.size()==(nums.size()/2));
    }
};