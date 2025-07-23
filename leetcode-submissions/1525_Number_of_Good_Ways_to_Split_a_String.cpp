class Solution {
public:
    int numSplits(string s) {
        unordered_map<char , int>left , right ;
        int count =0 ;
        for(char ch : s){
            right[ch]++;
        }
        for(int i =0 ;i<s.length();i++){
            left[s[i]]++;
            right[s[i]]--;
            if(right[s[i]]==0){
                right.erase(s[i]);
            }
            if(left.size()==right.size()){
                count++;
            }
        }
        return count ;
    }
};