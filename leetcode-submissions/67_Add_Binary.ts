function addBinary(a: string, b: string): string {
    let res:string ="";
    let i:number =a.length-1 ,j:number =b.length-1,carry:number =0;
    while(i>=0 || j>=0 || carry>0){
        let digitA:number =i>=0 ?parseInt(a[i]):0;
        let digitB:number =j>=0 ?parseInt(b[j]):0;
        i--;
        j--;
        //after this we will need to find the query 
        let sum:number =digitA+digitB+carry ;

        carry =Math.floor(sum/2);
        res=(sum%2).toString()+res;
        
    }
    if(carry>0){
        res=carry.toString()+res;
    }
    return res;
};