function maxSatisfied(customers: number[], grumpy: number[], minutes: number): number {
    let  j:number =0, maxUnsatisfaction:number =0 ;
    let current:number =0;
    const n:number = customers.length;
    for(j=0;j<minutes;j++){
        current+=(customers[j]*grumpy[j]); // if zero then nothing to add in answer
    }
    maxUnsatisfaction= current;
    
    // now j reached at minute
    while(j<n){
        current+=(customers[j]*grumpy[j]);
        current-=(customers[j-minutes]*grumpy[j-minutes]);
        maxUnsatisfaction= Math.max(maxUnsatisfaction, current);
        j++;
    }
    let already_satisfied:number =0;
    for(let i :number =0;i<n;i++){
        if(grumpy[i]==0){
            already_satisfied+=customers[i];
        }
    }
    return already_satisfied+maxUnsatisfaction;
    
};