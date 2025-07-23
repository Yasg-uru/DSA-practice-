class Solution {
public:
    unordered_map<string , int >mp;

    int solve(int s , int e , int steps , int k ){
        if(steps==0 ){
            return s==e;
        }
        string key = to_string(s)+".."+to_string(steps);
        if(mp.count(key)){
            return mp[key];
        }

        int add , sub;
      
            add = solve(s-1 ,e, steps-1,k  );
       
     
            sub= solve(s+1, e, steps-1, k);
        
        return mp[key]=add+sub;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        mp.clear();
        return solve(startPos, endPos , k , k );
    }
};