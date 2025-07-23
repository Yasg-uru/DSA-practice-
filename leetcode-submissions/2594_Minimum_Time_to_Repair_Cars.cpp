class Solution {
public:
    bool isPossible(long long time  , int cars ,vector<int>&ranks)
    {
        int TotalRepairedCars = 0 ;
        for(int i=0;i<ranks.size();i++){
            TotalRepairedCars += sqrt(time/ranks[i]);
        }
        return TotalRepairedCars>=cars;


    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long  l = 1;
        long long  maxRank = *max_element(ranks.begin(), ranks.end());
        long long  r = maxRank*cars*cars ;
        long long  result = -1 ;

        while(l<=r){
            long long  mid = l+(r-l)/2;// mid represents time 
            if(isPossible(mid, cars , ranks )){
                result = mid ;
                r= mid - 1;

            }else{
                l= mid+1;

            }

        }
        return result ; 

    }
};