class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
     unordered_map<int,int>mp;
     int pairs=0;
     for(int i=0;i<dominoes.size();i++){
        int a =dominoes[i][0];
         int b=dominoes[i][1];
        int key=min(a,b)*10+max(a,b);
        pairs+=mp[key];
        mp[key]++;
     }
     return pairs;
    }
};