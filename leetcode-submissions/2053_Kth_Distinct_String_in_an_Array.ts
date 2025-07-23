function kthDistinct(arr: string[], k: number): string {
    const mp=new Map<string,number>();
    for(let i=0;i<arr.length;i++){
        if(!mp.has(arr[i])){
            mp.set(arr[i],i);
        }else{
            mp.set(arr[i],mp.get(arr[i])+1);
        }
    }
    let cnt=0;
    for(let i=0;i<arr.length;i++){
        if(mp.get(arr[i])===1){
            cnt++;
        }
        if(cnt==k){
            return arr[i];
        }
    }
return "";
};