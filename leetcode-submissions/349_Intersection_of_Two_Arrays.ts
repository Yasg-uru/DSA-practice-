function intersection(nums1: number[], nums2: number[]): number[] {
    const map:Map<number , number >= new Map();
    const st:Set<number> = new Set(nums2);
    for(const num of nums1){
        map.set(num , (map.get(num) || 0 )+1);
        
    }
    const ans : number[] = [];
    for(const num of st){
        if(map.has(num)){
            ans.push(num);
        }
    }
    return ans  ;
};