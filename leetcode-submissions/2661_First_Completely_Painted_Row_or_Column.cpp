class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // we need to find the min indexes of to paint the columns 
        unordered_map<int,int>mp;
        int m=mat.size() ,n=mat[0].size();
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        //we stored the indexs of the arrays elements in the map 
        int minIndex=INT_MAX;
        for(int row=0;row<m;row++){
            int lastIndex=INT_MIN;
            
            for(int col=0;col<n;col++){
                int index=mp[mat[row][col]];
                lastIndex=max(lastIndex,index);
            }
            minIndex=min(minIndex,lastIndex);
        }
        for(int col=0;col<n;col++){
            int lastIndex=INT_MIN;
            for(int row=0;row<m;row++){
                int index=mp[mat[row][col]];
                lastIndex=max(lastIndex,index);
            }
            minIndex=min(minIndex,lastIndex);
        }
        return minIndex;

    }
};