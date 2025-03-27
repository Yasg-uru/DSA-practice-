function maxSubarrayLength(nums: number[], k: number): number {
    let left: number = 0, maxLen: number = 0;
    const freqMap: Map<number, number> = new Map();
    
    for (let right = 0; right < nums.length; right++) {
        // Update the frequency of nums[right]
        freqMap.set(nums[right], (freqMap.get(nums[right]) || 0) + 1);
        
        // If any element appears more than k times, shrink the window from the left
        while (freqMap.get(nums[right])! > k) {
            freqMap.set(nums[left], (freqMap.get(nums[left]) || 0) - 1);
            left++;
        }
        
        // Update max length of valid subarray
        maxLen = Math.max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
