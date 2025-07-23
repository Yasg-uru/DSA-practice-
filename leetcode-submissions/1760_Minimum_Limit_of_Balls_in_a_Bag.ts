function minimumSize(nums: number[], maxOperations: number): number {
    let maxEle: number = Math.max(...nums); // Find the maximum element in the array
    let left: number = 1, right: number = maxEle;
    let result: number = maxEle;

    while (left <= right) {
        let mid: number = Math.floor((left + right) / 2);

        if (isPossible(mid, nums, maxOperations)) {
            result = mid; // If mid is possible, it could be the minimum valid size
            right = mid - 1; // Try for a smaller size
        } else {
            left = mid + 1; // Increase size if mid is not possible
        }
    }
    return result;
}

function isPossible(mid: number, nums: number[], maxOperations: number): boolean {
    let totalOperations: number = 0;
    for (const num of nums) {
        let op: number = Math.ceil(num / mid) - 1; // Number of operations needed for this element
        totalOperations += op; // Accumulate total operations needed
    }
    return totalOperations <= maxOperations;
}
