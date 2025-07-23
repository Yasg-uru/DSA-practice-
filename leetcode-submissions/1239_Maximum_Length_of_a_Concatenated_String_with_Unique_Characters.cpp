class Solution {
public:
    unordered_map<string, int >mp;

    bool hasDuplicate(string& s1, string& s2){
        vector<int>f(26, 0);
        for(char ch:s1){
            if(f[ch-'a']>1) return true ;
            f[ch-'a']++;
        }
        for(char ch:s2){
            if(f[ch-'a']) return true;
        }
        return false;
    }
    int solve(vector<string>&arr, int i, string temp){
        if(i>=arr.size())return temp.length();
        int include = 0 ;
        int exclude = 0 ;
        if(mp.find(temp)!=mp.end()) return mp[temp];
        if(hasDuplicate( arr[i], temp)){
            exclude= solve(arr, i+1, temp);
        }else {
            include = solve(arr, i+1, temp+arr[i]);
            exclude = solve(arr, i+1, temp);
        }
        return mp[temp]=max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        mp.clear();
        return solve(arr, 0 , temp);

    }
};