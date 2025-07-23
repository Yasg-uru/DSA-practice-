class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
      unordered_map<int,int>mp;// it  stores color -> count 
      vector<int >arr(limit+1, -1);
      vector<int>result;

      for(auto& query : queries){
        int ball = query[0];
        int color  =query[1];
        if(arr[ball]!=-1){
            mp[arr[ball]]--;
            if(mp[arr[ball]]==0){
                mp.erase(arr[ball]);
            }
        }
        //assing new color 
        mp[color]++;
        arr[ball]=color;
        result.push_back(mp.size());

      }
      return result ;

    }
};