class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i =0 , j= 0;
        set<char>st(s.begin(), s.end());
        unordered_map<char , int >mp;
        int unique_count = st.size(), maxLength =0 ;
        while(j<s.length()){
            mp[s[j]]++;
            while(mp[s[j]]>2 ){
                mp[s[i]]--;
                // if(mp[s[i]]==0){
                //     mp.erase(s[i]);
                // }
                i++;
            }
            // if(mp.size()==unique_count){
                maxLength = max(maxLength , j-i+1);
            // }
            j++;
        }
        return maxLength ;
    }
};