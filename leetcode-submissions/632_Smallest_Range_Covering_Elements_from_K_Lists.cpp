class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
       int maxele=INT_MIN;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
       
       for(int i=0;i<nums.size();i++){
         pq.push({nums[i][0],{i,0}});
        maxele=max(maxele,nums[i][0]);
       } 
       //after finding that we have an range from 0 to maxelement of the list 
       // we need to minimize it by reducing the min and maxrange 
       vector<int>minRange={0,maxele};
       //after that we need to run the while loop until anyone list is not ended or exausted
       while(true){
        //extracting the min element and their information 
        auto [minele,indexPair]=pq.top();
        pq.pop();
        if(maxele-minele<minRange[1]-minRange[0]){
            minRange[0]=minele;
            minRange[1]=maxele;
        }
        if(indexPair.second==nums[indexPair.first].size()-1){
            break;
        }
        int nextele=nums[indexPair.first][indexPair.second+1];
        maxele=max(maxele,nextele);
        pq.push({nextele,{indexPair.first,indexPair.second+1}});

       }
       return minRange;
    }
};