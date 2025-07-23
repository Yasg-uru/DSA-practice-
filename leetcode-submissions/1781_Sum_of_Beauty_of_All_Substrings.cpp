class Solution {
public:
    int beautySum(string s) {
        // in this question we need to store the frequency of the substring then finding the minimum and maximum count 
        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<int>freq(26,0);
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;
            
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int i=0;i<26;i++){
                if(freq[i]!=0){
                    mini=min(mini,freq[i]);
                    maxi=max(maxi,freq[i]);
                }

            }
            ans+=maxi-mini;
            }
        }
        return ans;
    }
};