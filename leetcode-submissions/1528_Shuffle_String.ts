function restoreString(s: string, indices: number[]): string {
    const n:number = indices.length;
    const arr:string[]= new Array(n);
    for(let i:number = 0 ;i<n;i++){
        arr[indices[i]]= s[i]; 
    }
    return arr.join("");
};