function findArray(pref: number[]): number[] {
    const n:number =pref.length;
    const ans :number[]= new Array(n);
    ans[0]= pref[0];
    for(let i:number =1;i<n;i++){
        ans[i]= pref[i-1]^pref[i];
    }
    return ans;
};