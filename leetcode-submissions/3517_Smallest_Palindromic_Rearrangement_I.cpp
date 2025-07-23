class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int >mp;
        for(char &ch:s){
            mp[ch]++;
        }
        string half = "";
       string middle = "";
        
        for(const auto& ele : mp){
            char character = ele.first;
            int frequency = ele.second ;
           half+=string(frequency/2, character);
            if(frequency%2==1 ){
                middle= string(1, character) ;
            }
                
            
        }
        string reversedHalf = half; 
    reverse(reversedHalf.begin(), reversedHalf.end());
    
        return half+middle+reversedHalf ;
    }
};