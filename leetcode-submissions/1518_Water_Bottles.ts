function numWaterBottles(numBottles: number, numExchange: number): number {
    let ans:number=numBottles;
    while(numBottles>=numExchange){
        ans+=numBottles/numExchange;
        numBottles/=numExchange;
    }
    return ans;
};