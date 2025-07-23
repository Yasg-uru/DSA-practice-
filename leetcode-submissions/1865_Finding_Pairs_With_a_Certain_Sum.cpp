class FindSumPairs {
public:
vector<int>n1 , n2 ;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1  = nums1;
        n2 = nums2;
    }
    
    void add(int index, int val) {
        n2[index]+=val;
    }
    
    int count(int tot) {
        int count =0 ;
        for(int i =0 ;i<n1.size();i++){
            for(int j =0 ;j<n2.size();j++){
                if(n1[i]+n2[j]==tot){
                    count++;
                }
            }
        }
        return count ;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */