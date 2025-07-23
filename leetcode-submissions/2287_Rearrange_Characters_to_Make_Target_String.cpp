class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int>freq_s;
        unordered_map<char,int>freq_target;
        for(int i=0;i<s.size();i++){
            freq_s[s[i]]++;
        }
        for(char t:target){
            freq_target[t]++;
        }
        int result =INT_MAX ;
        for(auto const &[ch,count]:freq_target){
            if(freq_s[ch]==0){
                return 0;
            }
            result=min(result,freq_s[ch]/count);
        }
        return result;
       
    }
};