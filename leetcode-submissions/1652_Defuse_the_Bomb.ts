function decrypt(code: number[], k: number): number[] {
    const ans:number[]=Array.from({length:code.length},()=>0);
    if(k===0){
        return ans;
    }
    if(k>0){
        for(let i:number =0;i<code.length;i++){
            let j:number =(i+1)%code.length;
            let count :number =0;
            let temp:number =0;
            while(count <k){
                temp+=code[j];
                count ++;
                j=(j+1)%code.length;
            }
            ans[i]=temp;
        }
    }else if (k<0){
        for(let i:number =0;i<code.length;i++){
let j:number =(i-1+code.length)%code.length;
let count :number =0;
let temp:number =0;
while(count <Math.abs(k)){
    count ++;
    temp+=code[j];
    j=(j-1+code.length)%code.length;
}
ans[i]=temp;
        }
    }
    return ans;
};