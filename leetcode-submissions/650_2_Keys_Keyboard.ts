function minSteps(n: number): number {
    let curr:number =1;
    let prev:number =0;
    let ans:number =0;
    while ( curr<n){
if(n%curr===0){
prev=curr;
curr+=prev;
ans+=2;
}else{
    curr+=prev;
    ans++;
}
    }
return ans ;
};