function equalSubstring(s: string, t: string, maxCost: number): number {
    let i : number=0 , j:number =0 , currCost:number =0, maxWindow:number = Number.MIN_SAFE_INTEGER ;
    const n :number = s.length;

    while(j<n){
        currCost +=Math.abs(s[j].charCodeAt(0)-t[j].charCodeAt(0));
        while(currCost>maxCost){
            currCost -=Math.abs(s[i].charCodeAt(0)-t[i].charCodeAt(0));
            i++;
        }
    maxWindow = Math.max(maxWindow, j-i+1);
        j++;
    }
    return maxWindow;
};