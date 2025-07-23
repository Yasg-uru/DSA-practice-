class Solution {
public:
   static bool cmp(const vector<int>&a,const vector<int>&b){
        return a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        set<vector<int>>ans;
       
        for(int i=0;i<pairs.size();i++){
           for(int j=i+1;j<pairs.size();j++){
               if(pairs[i][1]<pairs[j][0]){
                  ans.insert(pairs[i]);
                  ans.insert(pairs[j]);
               }

           }
        }
        return ans.size();
    }
};