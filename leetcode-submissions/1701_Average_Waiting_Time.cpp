class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int idleTime=1;
        int waitingTime =0;
        for(int i=0;i<customers.size();i++){
            if(idleTime<=customers[i][0]){
                idleTime=customers[i][0]+customers[i][1];

            }else{
                idleTime=idleTime+customers[i][1];

            }
            waitingTime+=(idleTime-customers[i][0]);

        }
        return double(waitingTime/customers.size());
    }
};