class Solution {
public:
static bool cmp(const int &a ,const int &b){
    return b<a;

}

    int coinChange(vector<int>& coins, int amount) {
sort(coins.begin(),coins.end(),cmp);
//after we need to traverse this array and do something like greedy 
int count =0;
int i=0;
for(int i=0;i<coins.size();i++){
    cout<<coins[i]<<" ";
}
while(i<coins.size()){
    int coin=coins[i];
        if(amount==0){
          break; 
        }
    while(amount>=coin){
        amount-=coin;
        count++;
    }
    i++;

}
return (amount==0)?count:-1;

    }
};