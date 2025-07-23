class Solution {
public:
    int minSteps(int n) {
        int prev=0;
        int curr=1;
        int ans=0;
        while(curr<n){
            if(n%curr==0){
                prev=curr; //copy 
                curr+=prev;//paste
                ans+=2;
            }else{
                ans++;
//paste
curr+=prev;
            }
        }
        return ans;
    }
};