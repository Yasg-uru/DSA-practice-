class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        for(char ch :s){
            mp[ch]++;
        }
        int maxAns = INT_MIN;
        for(int i=0;i<s.length()-1;i++){
            char c1= s[i];
            char c2=s[i+1];
            if(c1!=c2 ){
                if(mp[c1]%2==1 and mp[c2]%2==0){

                    int diff= mp[c1]-mp[c2];
                    maxAns= max(maxAns , diff);
                }
                else if(mp[c1]%2==0 and mp[c2]%2==1){
                int diff= mp[c2]-mp[c1];
                    maxAns= max(maxAns , diff);
                }
            }
        }
            cout<<maxAns;
return maxAns ;
    }
};