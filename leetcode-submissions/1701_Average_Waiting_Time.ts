function averageWaitingTime(customers: number[][]): number {
    //i am solving this question by uisng the single thread application type approach 
    let idleTime=1;
    let watingTime=0;
    for(let i=0;i<customers.length;i++){
        if(idleTime<=customers[i][0]){
            idleTime=customers[i][1]+customers[i][0];
        }else{
            idleTime=idleTime+customers[i][1];

        }
        watingTime+=(idleTime-customers[i][0]);
    }
    return (watingTime/customers.length);

};