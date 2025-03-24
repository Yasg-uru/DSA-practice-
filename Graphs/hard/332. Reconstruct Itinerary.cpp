/*
    Problem: Reconstruct Itinerary (LeetCode 332)
    Approach: DFS + Backtracking
    
    - We construct an adjacency list where each airport points to its destinations (sorted lexicographically).
    - We use DFS to explore possible paths, ensuring we pick the lexicographically smallest one first.
    - Backtracking ensures that we construct a valid itinerary covering all tickets.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;  // Stores the final itinerary
    unordered_map<string, vector<string>> adj;  // Adjacency list (Graph representation)
    int numberOfTickets;  // Total number of tickets
    
    /**
     * Depth-First Search (DFS) to construct the itinerary.
     * @param fromAirport: The current airport being visited.
     * @param path: The current itinerary path being explored.
     * @return True if a valid itinerary is found, otherwise False.
     */
    bool DFS(string fromAirport, vector<string>& path) {
        path.push_back(fromAirport);
        
        // Base condition: If all tickets are used, store result and return true
        if (path.size() == numberOfTickets + 1) {
            result = path;
            return true;
        }
        
        // Reference to the list of destinations from the current airport
        vector<string>& neighbors = adj[fromAirport];
        
        for (int i = 0; i < neighbors.size(); i++) {
            string toAirport = neighbors[i];  // Pick the first available airport (smallest lexicographically)
            
            // Remove airport from list to simulate using the ticket
            neighbors.erase(neighbors.begin() + i);
            
            if (DFS(toAirport, path)) return true;  // If itinerary is found, return true
            
            // Backtrack: Restore the airport back to the list
            neighbors.insert(neighbors.begin() + i, toAirport);
        }
        
        path.pop_back();  // Remove last added airport to explore other options
        return false;
    }
    
    /**
     * Finds the itinerary given the list of tickets.
     * @param tickets: List of [from, to] tickets.
     * @return The lexicographically smallest valid itinerary.
     */
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numberOfTickets = tickets.size();
        
        // Build the adjacency list (Graph)
        for (auto& ticket : tickets) {
            string from = ticket[0], to = ticket[1];
            adj[from].push_back(to);
        }
        
        // Sort destinations at each airport to ensure smallest lexicographical order
        for (auto& entry : adj) {
            sort(entry.second.begin(), entry.second.end());
        }
        
        vector<string> path;
        DFS("JFK", path);  // Always start from JFK
        return result;
    }
};

// Example Usage
int main() {
    Solution solution;
    vector<vector<string>> tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    
    vector<string> itinerary = solution.findItinerary(tickets);
    
    cout << "Reconstructed Itinerary: ";
    for (const string& stop : itinerary) {
        cout << stop << " ";
    }
    cout << endl;
    
    return 0;
}