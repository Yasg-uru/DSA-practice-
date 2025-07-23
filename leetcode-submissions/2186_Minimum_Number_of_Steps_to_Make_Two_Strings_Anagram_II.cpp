class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char , int >mp1 ,mp2;
        for(char ch : s){
            mp1[ch]++;
        }
        for(char ch : t){
            mp2[ch]++;
        }
        int ans =0 ;
        for(auto& [ch , count]:mp1){
             if(count>mp2[ch])ans+=(count-mp2[ch]);
        }
        for(auto& [ch,count]:mp2){
            if(count>mp1[ch])ans+=(count-mp1[ch]);
        }
        return ans ;

    }
};