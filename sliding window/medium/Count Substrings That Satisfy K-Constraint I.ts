function countKConstraintSubstrings(s: string, k: number): number {
    let i: number = 0, j: number = 0;
    let count0: number = 0, count1: number = 0;
    const n: number = s.length;
    let ans: number = 0;
    
    while (j < n) {
        // Count occurrences of '0' and '1' in the current window
        if (s[j] === "0") {
            count0++;
        } else {
            count1++;
        }
        
        // Shrink the window if either count exceeds k
        while (count0 > k && count1 > k) {
            if (s[i] === "0") {
                count0--;
            } else {
                count1--;
            }
            i++;
        }
        
        // Add the number of valid substrings ending at index j
        ans += (j - i + 1);
        j++;
    } 
    
    return ans;
}
