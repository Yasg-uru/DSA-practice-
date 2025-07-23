function countKConstraintSubstrings(s: string, k: number): number {
    let i :number =0 , j:number =0, count0:number  =0 , count1:number =0;
    const n : number =s.length;
    let ans :number =0;
    while(j<n){
        if(s[j]=="0"){
            count0++;
        }else{
            count1++;
        }
        while(count0>k && count1>k){
            if(s[i]=="0"){
            count0--;
            }else{
                count1--;
            }
            i++;

        }
        ans+=(j-i+1);
        j++;

    } 
    return ans ;
};