class Solution {
public:
    string reverseVowels(string s) {
        //now we need to make a set of vowels 
        unordered_set<char>vowels={'a','e','i','o','u','A','E','I','O','U'};
        int left=0;
        int right=s.size()-1;


        // now we need to make while loop for if
        while(left<right){
            while(left<right and vowels.find(s[left])==vowels.end()){
                left++;
            }
            while(left<right and vowels.find(s[right])==vowels.end()){
                right--;
            }

            if(left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};