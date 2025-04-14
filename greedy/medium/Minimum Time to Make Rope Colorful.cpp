
class Solution {
    public:
        /*
            Approach:
            - We need to remove balloons such that no two adjacent balloons have the same color.
            - When there are consecutive balloons with the same color, 
              we should remove the one with the smaller removal time.
            - We use a greedy approach:
                -> Keep track of the maximum removal time (prevMax) in the current group of same-colored balloons.
                -> If the current balloon color is different from the previous one, reset prevMax.
                -> Add the minimum of prevMax and current balloon's removal time to the total time.
        */
    
        int minCost(string colors, vector<int>& neededTime) {
            int prevMax = 0; // To store the maximum removal time in the current group
            int time = 0;    // To store the total minimum time required
    
            for(int i = 0; i < colors.size(); i++) {
                
                // If current balloon color is different from previous, reset prevMax
                if(i > 0 && colors[i] != colors[i - 1]) {
                    prevMax = 0;
                }
    
                int currTime = neededTime[i];
    
                // Add the minimum of previous max time and current time
                // Because we want to remove the smaller one
                time += min(prevMax, currTime);
    
                // Update prevMax for the current group
                prevMax = max(prevMax, currTime);
            }
    
            return time;
        }
    };
    