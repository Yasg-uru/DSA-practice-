class Solution {
public:
    int commonPrefixLength(string a, string b ){
        int minLength = min(a.length(), b.length());
        int i =0 ;
        while(i<minLength and a[i]==b[i]){
            i++;
        }
        return i ;
    }
    
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int>prefixArr(n-1);
        for(int i =0 ;i<n-1;i++){
            prefixArr[i]= commonPrefixLength(words[i], words[i+1]);
            
        }
        vector<int>ans(n);
        for(int i =0 ;i<n;i++){
            int maxLength =0 ;
            if(i>0 and i<n-1){
                maxLength = max(maxLength , commonPrefixLength(words[i-1], words[i+1]));
            }
            for(int  j =0 ;j<n-1;j++){
                if(j==i or j+1==i){
                    continue;
                }
                maxLength = max(maxLength, prefixArr[j]);
            }
        ans[i]= maxLength;
        }
    return ans;
    }
};