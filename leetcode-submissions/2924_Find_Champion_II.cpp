class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // we need to store the number of incomming edges so we can easily identify which is the champion
       set<int>incomming;
        for(int i=0;i<edges.size();i++){
           incomming.insert(edges[i][1]);
        }
        //after this we will need to check the count of the missing nodes 
        int count =0;
            int ans=0;
        for(int i=0;i<edges.size();i++){
        if(incomming.find(edges[i][0])==incomming.end()){
            count ++;
            ans=edges[i][0];

        }        
        }
        return count >1?-1:ans;
    }
};