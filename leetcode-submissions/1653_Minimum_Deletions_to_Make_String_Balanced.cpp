class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
       vector<int>a_prefix(n,0);
       vector<int>b_prefix(n,0);
       // we need to delete the b from the left side 
       for(int i=1;i<n;i++){
        a_prefix[i]=a_prefix[i-1];
        if(s[i-1]=='b'){
            a_prefix[i]+=1;
        }
       }
       for(int i=n-2;i>=0;i--){
        b_prefix[i]=b_prefix[i+1];
        if(s[i+1]=='a'){
            b_prefix[i]+=1;
        }
       }
       int minDel=INT_MAX;
       for(int i=0;i<n;i++){
        minDel=min(minDel,a_prefix[i]+b_prefix[i]);
       }
       return minDel;
    }
};