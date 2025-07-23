class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i =0 ,j=0 , m = word1.length(), n = word2.length();
        bool is_chance_of_i= true;
        while(i<m and j<n){
            if(is_chance_of_i){
               ans+=word1[i];
               i++;
               is_chance_of_i= false; 
            }else{
                ans += word2[j];
                j++;
                is_chance_of_i= true ;

            }
        }
        while(i<m){
            ans+=word1[i];
            i++;
        }
        while(j<n){
            ans+=word2[j];
            j++;
        }
        return ans ;
    }
};