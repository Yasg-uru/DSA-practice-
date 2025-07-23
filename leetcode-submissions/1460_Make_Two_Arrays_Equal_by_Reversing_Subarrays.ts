function canBeEqual(target: number[], arr: number[]): boolean {
    arr.sort();
    target.sort();
    for(let i=0;i<arr.length;i++){
        if(arr[i]!==target[i]){
            return false;
        }
    }
    return true ;
};