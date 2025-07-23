class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int balance=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='L'){
                balance++;
                if(balance==0){
                    ans++;
                }

            }else{
                balance--;
                if(balance==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};