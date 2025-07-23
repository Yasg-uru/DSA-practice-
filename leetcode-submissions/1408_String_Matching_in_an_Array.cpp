class Solution {
public:
    bool isSubstrings(string s1,string s2){
            return s1.find(s2)!=std::string::npos;
    }
    static bool cmp(const string&s1,const string&s2){
        return s1.length()<s2.length();
    }
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string>s;
    sort(words.begin(),words.end(),cmp);
      for(int i=0;i<words.size();i++){
        for(int j=i+1;j<words.size();j++)
        {
            if(isSubstrings(words[j],words[i])){
                s.insert(words[i]);
            }
         

        }
      }
      vector<string>ans;
      for(auto str:s){
        ans.push_back(str);
      }
      return ans ;

    }
};