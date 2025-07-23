class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
    //using set for this is very efficient method for solving this question
    int n1=nums1.size();
    int n2=nums2.size();
    set<int>s1;
    if(n1>=n2){
        s1.insert(nums1.begin(),nums1.end());
       for(int i=0;i<n2;i++){
           if(s1.count(nums2[i])){
               return nums2[i];
           }
       }

    }else{
        s1.insert(nums2.begin(),nums2.end());
          for(int i=0;i<n1;i++){
           if(s1.count(nums1[i])){
               return nums1[i];
           }
       }
    }

return -1;
        
    }
};