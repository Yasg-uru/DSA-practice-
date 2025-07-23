function countSeniors(details: string[]): number {
let ans:number=0;
for(let i=0;i<details.length;i++){
    let str=details[i];
    let s=str.slice(11,13);

   let digit:number=parseInt(s);
    if(digit>60){
        ans+=1;
    }

}
return ans;
};