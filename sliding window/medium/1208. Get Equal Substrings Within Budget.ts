function equalSubstring(s: string, t: string, maxCost: number): number {
    let left: number = 0, currentCost: number = 0;
    let maxLength: number = 0;
    const n: number = s.length;

    // Sliding window approach
    for (let right = 0; right < n; right++) {
        // Calculate the transformation cost of the current character
        currentCost += Math.abs(s[right].charCodeAt(0) - t[right].charCodeAt(0));

        // If cost exceeds maxCost, shrink the window from the left
        while (currentCost > maxCost) {
            currentCost -= Math.abs(s[left].charCodeAt(0) - t[left].charCodeAt(0));
            left++;
        }

        // Update maximum valid substring length
        maxLength = Math.max(maxLength, right - left + 1);
    }

    return maxLength;
}