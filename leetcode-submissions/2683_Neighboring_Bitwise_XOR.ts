function doesValidArrayExist(derived: number[]): boolean {
    const n:number =derived.length;
    const original:number[]=new Array(n);
    original[0]=0;
    for(let i:number =0;i<n-1;i++){
        original[i+1]=derived[i]^original[i];
    }
    if((original[n-1]^original[0])===derived[n-1]){
        return true;
    }
    original[0]=1;
    for(let i:number =0;i<n-1;i++){
        original[i+1]=derived[i]^original[i];
    }
     if((original[n-1]^original[0])===derived[n-1]){
        return true;
    }
    return false;
};