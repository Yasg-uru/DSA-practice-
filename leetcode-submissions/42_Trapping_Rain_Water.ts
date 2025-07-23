function trap(height: number[]): number {
    const n :number = height.length;
    const maxLeftHeights :number[]=new Array(n);
    const maxRightHeights :number[]=new Array(n);
    let maxLeftHeight = Number.MIN_SAFE_INTEGER;
    let maxRightHeight= Number.MIN_SAFE_INTEGER;
    for(let i:number=0;i<n;i++){
        maxLeftHeight= Math.max(maxLeftHeight, height[i]);
        maxLeftHeights[i]=maxLeftHeight;

    }
    for(let i:number = n-1;i>=0;i--){
        maxRightHeight= Math.max(maxRightHeight, height[i]);
        maxRightHeights[i]= maxRightHeight;
    }
    let ans :number =0;

    for(let i:number =0;i<n;i++){
        ans+=(Math.min(maxRightHeights[i],maxLeftHeights[i])-height[i]);
    }
    return ans ;
};