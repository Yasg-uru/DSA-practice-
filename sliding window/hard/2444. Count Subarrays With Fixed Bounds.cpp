#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            // Index of the most recent invalid element (out of minK to maxK range)
            int culpritIndex = -1;
            
            // Indices of the most recent occurrences of minK and maxK
            int minKIndex = -1, maxKIndex = -1;
            
            int j = 0; // Right pointer for iterating through the array
            int n = nums.size(); // Size of the array
            long long totalWindows = 0; // Count of valid subarrays
            
            while (j < n) {
                // Update the index of the last occurrence of minK
                if (nums[j] == minK) {
                    minKIndex = j;
                }
                
                // Update the index of the last occurrence of maxK
                if (nums[j] == maxK) {
                    maxKIndex = j;
                }
                
                // If an invalid element (out of range) is found, update culpritIndex
                if (nums[j] < minK || nums[j] > maxK) {
                    culpritIndex = j;
                }
                
                // If both minK and maxK are found in the current valid window
                if (minKIndex != -1 && maxKIndex != -1) {
                    // Find the smaller index among minKIndex and maxKIndex
                    int smaller = min(minKIndex, maxKIndex);
                    
                    // Number of valid subarrays ending at j
                    int temp = smaller - culpritIndex;
                    totalWindows += (temp <= 0) ? 0 : temp;
                }
                
                j++; // Move to the next element
            }
            
            return totalWindows; // Return the total count of valid subarrays
        }
    };
    