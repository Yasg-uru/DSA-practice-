/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function(nums, k) {
    let start=0;
    let end=0;
    let product=1;
    let count=0;
    while(end<nums.length){
        product*=nums[end];
        end++;
        while(start<nums.length && product>=k){
            product/=nums[start];
            start++;
        }
        if(product<k){
            count+=(end-start+1);
        }
        return count;
    }
};