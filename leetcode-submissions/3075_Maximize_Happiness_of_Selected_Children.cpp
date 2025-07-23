class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        int turns=0;

        sort(happiness.begin(),happiness.end());
for(int i=happiness.size()-1;i>=0;i--){
    if(turns==k){
        break;
    }
    ans=ans+max(happiness[i]-turns,0);
    turns++;
}
return ans;
    }
};