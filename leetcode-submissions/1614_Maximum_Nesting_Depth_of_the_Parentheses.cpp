class Solution {
public:
    int maxDepth(string s) {
        //in this code we dont use stack
        int currdepth=0;
        int maxdepth=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                currdepth++;
                maxdepth=max(maxdepth,currdepth);
            }else if(s[i]==')'){
                currdepth--;

            }
        }
        return maxdepth;
    }
};