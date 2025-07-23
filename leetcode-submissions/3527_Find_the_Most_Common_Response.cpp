class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n = responses.size();
        unordered_map<string , int>mp;
        for(int i =0 ;i<n;i++){
            unordered_set<string >s;
            for(string& str : responses[i]){
                s.insert(str);
            }
            for(auto& str : s){
                mp[str]++;
            }
        }
        string result = "";
        int maxFreq = 0 ;
        for(auto& it : mp){
            if(maxFreq<it.second or ( it.second==maxFreq and it.first<result )){
                result = it.first;
            maxFreq = it.second ;
            }

    
    }
    return result ;
    }

};