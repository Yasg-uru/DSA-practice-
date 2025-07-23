class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        unordered_map<char , int >mp1, mp2;
        for(char ch : name){
        mp1[ch]++;
        }
        for(char ch : typed){
        mp2[ch]++;
        }
        for(auto& ele : mp2){
            if(mp1[ele.first]>ele.second){
            return false;
            }
        }
        return true ;
    }
};