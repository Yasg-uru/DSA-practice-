class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        string result = "";
        unordered_map<int , pair<string , string>>mp;
        for(int i =0 ;i<indices.size();i++){
            mp[indices[i]]= {sources[i], targets[i]};
        }
        for(int i =0;i<n;i++){
            if(mp.count(i)){
                string target = mp[i].second;
                string source = mp[i].first;
                if(s.substr(i ,source.size())==source){
                    result+=target;
                    i+=source.size();
                    continue ;
                }
                    
            }
            result+=s[i];
        }
        return result ;
    }
};