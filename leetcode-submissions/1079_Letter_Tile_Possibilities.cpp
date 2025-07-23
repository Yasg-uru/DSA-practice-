class Solution {
public:
    void solve(string& tiles , unordered_set<string>&result , string &curr, vector<bool>&isUsed, int n ){
        result.insert(curr);
        for(int i=0;i<n;i++){
            // do 
            if(isUsed[i]) continue ;
            isUsed[i]=true ;
            curr.push_back(tiles[i]);

            //explore
            solve(tiles, result, curr, isUsed, n );

            //undo
            isUsed[i]=false;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        string curr= "";
        unordered_set<string>result;
        int n = tiles.length();
        vector<bool>isUsed(n , false);

        solve(tiles , result, curr, isUsed, n );
        return result.size()-1;
    }
};