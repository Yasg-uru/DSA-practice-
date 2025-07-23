class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char>minToRight(n);
        minToRight[n-1]= s[n-1];
        for(int i = n-2;i>=0;i--){
            minToRight[i]= min(minToRight[i], minToRight[i+1]);

        }
        string t = "", ans = "";
        int i =0 ;
        while(i<n){
            t.push_back(s[i]);
            char minChar = i+1<n?minToRight[i+1]: s[i];
            while(not t.empty() and t.back()<=minChar)
            {
                ans.push_back(t.back());
                t.pop_back();

            }
            i++;
        }
        while(not t.empty()){
            ans.push_back(t.back());
            t.pop_back();
        }
        return ans ;
    }
};