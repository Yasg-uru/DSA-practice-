class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size()/3;
        sort(piles.begin(),piles.end());
        int i=piles.size()-2;
        int maxsum=0;
        //now starting from second last element
        int j=0;
        while(j<n and i>=0){
            maxsum+=piles[i];
            i=i-2;
            j++;
        }
        return maxsum;

    }
};