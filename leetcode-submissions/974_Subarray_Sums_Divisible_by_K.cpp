class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>remaindercount;
        remaindercount[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remainder=sum%k;
            if(remainder<0){
                remainder+=k;

            }
            if(remaindercount.find(remainder)!=remaindercount.end())
            {
ans+=remaindercount[remainder];

            }
                remaindercount[remainder]++;


            
        }
        return ans;

    }
};