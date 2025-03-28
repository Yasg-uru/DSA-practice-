/**
 * Function to count the number of valid substrings where both '0's and '1's appear at most `k` times.
 * Uses the sliding window (two-pointer) approach for an efficient O(n) solution.
 *
 * @param {string} s - The binary string consisting of '0' and '1'.
 * @param {number} k - The maximum allowed occurrences of '0' and '1' in a valid substring.
 * @returns {number} - The total number of valid substrings.
 */
function countKConstraintSubstrings(s: string, k: number): number {
    let i: number = 0, j: number = 0; // Two pointers for the sliding window
    let count0: number = 0, count1: number = 0; // Counters for '0's and '1's
    const n: number = s.length;
    let ans: number = 0; // Stores the final count of valid substrings

    // Iterate through the string using the right pointer `j`
    while (j < n) {
        // Update counts based on the character at position `j`
        if (s[j] === "0") {
            count0++;
        } else {
            count1++;
        }

        // If both '0's and '1's exceed the limit `k`, shrink the window from the left
        while (count0 > k && count1 > k) {
            if (s[i] === "0") {
                count0--;
            } else {
                count1--;
            }
            i++; // Move the left pointer forward
        }

        // The number of valid substrings ending at `j` is `(j - i + 1)`
        ans += (j - i + 1);

        // Expand the window by moving the right pointer `j`
        j++;
    }

    return ans;
}



/**
 * Brute-force solution to count the number of valid substrings where
 * both '0's and '1's appear at most `k` times.
 * 
 * Time Complexity: O(n²) - Iterates over all possible substrings.
 * Space Complexity: O(1) - Uses only a few integer variables.
 * 
 * @param {string} s - A binary string consisting of '0' and '1'.
 * @param {number} k - The maximum allowed occurrences of '0' and '1' in a valid substring.
 * @returns {number} - The total number of valid substrings.
 */
function countKconstraintSubstrings(s: string, k: number): number {
    let ans: number = 0; // Stores the final count of valid substrings
    const n: number = s.length;

    // Iterate over all possible starting points of substrings
    for (let i = 0; i < n; i++) {
        let count0: number = 0, count1: number = 0; // Counters for '0's and '1's

        // Iterate over all possible ending points of substrings
        for (let j = i; j < n; j++) {
            // Update the count based on the current character
            if (s[j] === '0') {
                count0++;
            } else {
                count1++;
            }

            // If either '0' or '1' count exceeds k, stop checking further substrings
            if (count1 > k && count0 > k) {
                break;
            }

            // If the substring satisfies the constraint, count it
            ans++;
        }
    }

    return ans;
}
