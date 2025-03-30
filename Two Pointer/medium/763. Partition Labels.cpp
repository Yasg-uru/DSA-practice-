#include<bits/stdc++.h>
using namespace std;
// 763. Partition Labels
class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char, int> lastIndexMap; // Stores the last occurrence of each character in the string
            
            // Step 1: Populate the map with the last index of each character
            for (int i = 0; i < s.length(); i++) {
                lastIndexMap[s[i]] = i;
            }
            
            vector<int> partitionSizes; // Stores the sizes of partitions
            int maxIndex = 0;  // Keeps track of the farthest index of any character in the current partition
            int partitionStart = 0; // Marks the start of the current partition
            
            // Step 2: Iterate through the string to determine partitions
            for (int i = 0; i < s.length(); i++) {
                maxIndex = max(maxIndex, lastIndexMap[s[i]]); // Update max index for the current partition
                
                // If the current index matches the maxIndex, we have found a partition
                if (i == maxIndex) {
                    partitionSizes.push_back(i - partitionStart + 1); // Compute partition size and add to the result
                    partitionStart = i + 1; // Update the start of the next partition
                }
            }
            
            return partitionSizes; // Return the partition sizes
        }
    };
    