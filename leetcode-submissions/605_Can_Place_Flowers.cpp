class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]!=1 and flowerbed[i-1]!=1 and flowerbed[i+1]!=1){
                n--;
            }
        }
        if(n!=0){
            return false;
        }else{
            return true;
        }
    }
};