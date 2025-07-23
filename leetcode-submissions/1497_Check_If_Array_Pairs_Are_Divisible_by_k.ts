function canArrange(arr: number[], k: number): boolean {
    let i=0;
    let j=arr.length-1;
    let ans=true;
    while(i<=j){
        if((arr[i]+arr[j])%k!=0){
            ans=false;
            return ans;
        }
        i++;
        j--;

    }
    return ans ;
};