function checkIfExist(arr: number[]): boolean {
    // i guess first we need to sort this array 
    // [10,5,3,2]
    // i=0,j=3
    //check if arr[j]*2<arr[i]  , then we need to decreament the jth pointer 
    // 
    arr.sort((a,b)=>b-a);
    //this sorts in decreasing order
    let i:number =0;
    let j:number =arr.length-1;
    while(i<j){
if(arr[i]==(arr[j]*2)){
    return true ;

}else if (arr[i]>(arr[j]*2)){
    j--;
}else{
    i++;
}
    }
    return false;
};