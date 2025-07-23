class Solution {
public:
    bool canShip(vector<int>&weights , int capacity , int days)
    {
        int curr_weight =0 ;
        int used_days =1 ;
        for(int weight :weights){
            if((curr_weight+weight)>capacity){
                curr_weight =weight ;
                used_days++;
            }else{
                curr_weight+=weight;
            }
        }
        return used_days<=days ;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(begin(weights), end(weights));
        int right = accumulate(begin(weights ), end(weights), 0);
        int min_weight = INT_MAX;
        while(left<=right){
            int mid = (left+right)/2;
            if(canShip(weights , mid , days)==true){
                min_weight = mid ;
                right = mid-1;
            }else {
                left = mid+1;
            }
        }
        return min_weight;
    }
};