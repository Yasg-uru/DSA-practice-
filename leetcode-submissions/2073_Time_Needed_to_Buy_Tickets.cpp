class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        //now solving this question by using the approach that can able to solve this question easily with the help of the single loop only and creating the conditional statements
        //now we are using the while loop which is always true 
        int time =0;

        while(true){
            for(int i=0;i<tickets.size();i++){
if(tickets[i]!=0){
    time++;
    tickets[i]=tickets[i]-1;

}
if(tickets[k]==0 ){
    return time;
}
            }
        }
return 0;
    }
};