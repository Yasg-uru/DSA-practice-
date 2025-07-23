class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int>mp;
        for(int i=0;i<s.length();i++){
            string curr="";
            for(int j=i;j<s.length();j++){
                if(curr.empty() or curr.back()==s[j]){
                    curr+=s[j];
                    mp[curr]++;

            }else {
                break;
            }
            }
        }
        int result=0;

        // we need to check whether the string occurs thrice or not 
        for(auto &ele:mp){
            if(ele.second>=3){
                result++;

            }
        }
        
        return result==0?-1:result;
    }
};