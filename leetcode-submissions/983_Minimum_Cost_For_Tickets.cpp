class Solution {
public:
    int solve(int i,vector<int>&costs,vector<int>&days,int n ){
        if(i>=n){
            return 0;
        }
        // from the current index we need to pay 2 rupee for the day 1
        int cost_1_day=costs[0]+solve(i+1,costs,days,n);
        int j=i;
        int max_days=days[i]+7;
        while(j<n and days[j]<max_days){
            j++;
        }
        int cost_7_days=costs[1]+solve(j,costs,days,n);
        j=i;
        max_days=days[i]+30;
        while(j<n and days[j]<max_days){
            j++;
        }
        int cost_30_days=costs[2]+solve(j,costs,days,n);
        return min(cost_1_day,min(cost_7_days,cost_30_days));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        return solve(0,costs,days,n);

    }
};