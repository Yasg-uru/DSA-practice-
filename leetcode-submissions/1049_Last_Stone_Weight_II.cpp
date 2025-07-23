class Solution {
public:
    int t[31][3001];
    int n ;
    
    int solve(vector<int>&stones , int i, int &target, int currSum ){
        
        if(i>=n)
        {
            return currSum;
        }
        if(t[i][currSum]!=-1){
            return t[i][currSum];
        }
        int take =0 ;
        if((currSum+stones[i])<target){
            take = solve(stones , i+1 , target , currSum+stones[i]);
        }
        int not_take = solve(stones , i+1, target , currSum);
        return t[i][currSum]= max(take , not_take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(t ,-1 , sizeof(t));
        n = stones.size();
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        int halfSum  =totalSum/2;
        int maxSubset = solve(stones , 0, halfSum , 0 );
        return totalSum-2*maxSubset;
        
    }
};