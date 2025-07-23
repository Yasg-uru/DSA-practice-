class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>st;
        for(char ch : jewels){
            st.insert(ch);
        }
        int ans =0 ;
        for(char stone : stones){
            if(st.count(stone)){
                ans++;
            }
        }
        return ans ;
    }
};