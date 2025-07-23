class Solution {
public:
    bool isMatch(string& num , string&pattern){
        for(int i=0;i<pattern.length();i++){
            if(pattern[i]=='I' and num[i]>num[i+1]) return false;
            if(pattern[i]=='D' and num[i]<num[i+1]) return false;
        }
        return true;
    }
    string smallestNumber(string pattern) {
        string num = "";
        int n = pattern.length();
        for(int i=1;i<=n+1;i++){
            num.push_back(i+'0');
        }
        while(not isMatch(num, pattern)){
            std::next_permutation(num.begin(),num.end());
        }
        return num;
    }
};