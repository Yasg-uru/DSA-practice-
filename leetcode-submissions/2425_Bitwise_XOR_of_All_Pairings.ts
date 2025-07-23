function xorAllNums(nums1: number[], nums2: number[]): number {
    const map:Map<number,number>=new Map();
    for(const ele of nums1){
       
            map.set(ele,nums2.length);
        
    }
    for(const ele of nums2){
        
            map.set(ele,nums1.length);

    }
    let xor:number=0;
    for(const [element,frequency] of map.entries()){
        console.log(`${element}->${frequency}`);
        if(frequency%2){
            xor^=element;
        }
    }
    return xor;
};