function maximumUnits(boxTypes: number[][], truckSize: number): number {
    boxTypes.sort((boxA,boxB)=>boxB[1]-boxA[1]);
    // after sorting we need to use the exact concept of the fractional knapsack 
   let ans :number =0;

   for(let i:number =0;i<boxTypes.length;i++){
    if(truckSize>=boxTypes[i][0]){
        truckSize-=boxTypes[i][0];
        ans +=(boxTypes[i][0]*boxTypes[i][1]);
    }else {
        // if we have not a sufficient size then we need to take a part of it according to the remaining trucksize 
        ans+=truckSize*boxTypes[i][1];
        return ans ;
    }
   }
   return ans  ;
};