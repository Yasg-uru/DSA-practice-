class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>ans(s.size(),0);
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                    if(s[j]==c){
                        int dist=abs(i-j);
                        ans[i]=dist;
                        break;

                    }
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(s[j]==c){
                    int dist=abs(i-j);
                    int ele=ans[i];
                    ans[i]=min(ele,dist);
                }

            }
        }
        return ans;
    }
};