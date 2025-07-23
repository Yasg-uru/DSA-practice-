class Solution {
public:
 bool allZero(vector<int>&freq){
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true ;
    }
    vector<int> findAnagrams(string txt, string pat) {
        vector<int>freq(26 ,0);
        int k = pat.size();
        for(int i=0;i<k;i++){
            int ch = pat[i];
            freq[ch-'a']++;
        }
        int j=0;
        int i =0 ;
        vector<int>result;
        while(j<txt.size()){
            freq[txt[j]-'a']--;
            if(j-i+1==k){
                if(allZero(freq)){
                    result.push_back(i);
                }
                freq[txt[i]-'a']++;
                i++;
            }
            j++;
        }
        return result ;
    }
};