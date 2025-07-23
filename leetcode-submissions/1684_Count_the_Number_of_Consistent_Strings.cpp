class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<int>unique(allowed.begin(),allowed.end());
        int ans=0;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            bool flag=true;
            for(char ch:word){
                if(!unique.count(ch)){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans+=1;
            }
            
        }
        return ans;
    }
};