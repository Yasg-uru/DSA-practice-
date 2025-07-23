class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans ;
       int i =0 , n = s.length();
       while((i+k)<=n){
        string substring = s.substr(i , k);
        ans.push_back(substring);
        i+=k;
       }
       if(i<n){
        string lastChunk = s.substr(i);
        while(lastChunk.size()<k){
            lastChunk.push_back(fill);
        }
        ans.push_back(lastChunk);
       }
return ans ;
    }
};