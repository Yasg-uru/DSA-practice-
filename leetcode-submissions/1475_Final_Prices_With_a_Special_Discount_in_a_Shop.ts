function finalPrices(prices: number[]): number[] {
    let ans:number[]=new Array(prices.length);
    ans= prices;
    for(let i:number =0;i<prices.length;i++){
        for(let j:number =i+1;j<prices.length;j++){
            if(prices[j]<=prices[i]){
                ans[i]=prices[i]-prices[j];
                break;
            }
        }
        
    }
    return ans ;
};