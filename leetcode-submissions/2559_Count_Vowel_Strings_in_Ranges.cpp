class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        set<char>vowels({'a','i','e','o','u'});
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int temp =0;
            while(start<=end){
                for(char ch :words[start]){
                    if(vowels.find(ch)!=vowels.end()){
                        temp++;
                        break;
                    }
                }
                start++;


            }
            ans.push_back(temp);

        }
        return ans ;
    }
};