class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        unordered_map<char , int >mp;
        for(char ch : t){
            mp[ch]++;

        }
        int i=0;
        int j =0;
        int n = s.size();
        int required_count = t.size();
        int minWindowSize = INT_MAX;
        int start_i= -1 ;

        while(j<n){
            char char_j = s[j];
            if(mp[char_j]>0){
                required_count--;
            }
            mp[char_j]--;
            // its time to shrink if the required count becomes 0
            while(required_count==0){
                if(j-i+1<minWindowSize){
                    minWindowSize = j-i+1;
                    start_i= i;

                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    required_count++;
                }
                i++;
                
            }
            j++;
            
        }
        return (minWindowSize==INT_MAX)?"":s.substr(start_i, minWindowSize);
    }
};