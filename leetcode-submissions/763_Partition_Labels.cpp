class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int >mp; // it stores character to last index 
        for(int i=0;i<s.length();i++){
            mp[s[i]]= i ;
        }
        int maxIndex = -1;
        int lastIndex = 0 ;
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            maxIndex = max(mp[s[i]], maxIndex);
            if(maxIndex==i){
                // partition 
                ans.push_back(i-lastIndex+(lastIndex==0));
                lastIndex= i;
                maxIndex= -1;
            }

        }
        return ans ;
    }
};