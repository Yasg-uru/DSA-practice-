function findTheWinner(n: number, k: number): number {
    //we need to use concept of  circular indexing 
    //creating an array from the numbers 
    let array=[];

    for(let i=1;i<=n;i++){
array.push(i);
    }
    //after that we need to create a while loop 
    k=k-1;
    let index=0;

    while(array.length>1){
index=(index+k)%array.length;
array.splice(index,1);
    }
    return array[0];
};