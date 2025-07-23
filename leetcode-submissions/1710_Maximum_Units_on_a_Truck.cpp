class Solution {
public:


    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
       sort(boxTypes.begin(),boxTypes.end(),[] (auto &a,auto &b){return a[1]>b[1];});
           
    int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
                ans+=boxTypes[i][1]*boxTypes[i][0];
                truckSize=truckSize-boxTypes[i][0];
            }else{
                ans+=boxTypes[i][1]*truckSize;
                truckSize=0;
            }
        }
        return ans;
}
    
};