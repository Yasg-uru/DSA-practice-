function intersect(nums1: number[], nums2: number[]): number[] {
    const set=new Set(nums2);
    let answer=[];

    for(let i=0;i<nums1.length;i++){
        if(set.has(nums1[i])){
answer.push(nums1[i]);
        }
    }
    return answer;
};