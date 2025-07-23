class Solution {
public:
    
    int maxFreqSum(string s) {
    unordered_set<char>st;
        unordered_map<char , int >mp;
        
        st.insert('a');
        st.insert('e');
        st.insert('o');
        st.insert('i');
        st.insert('u');
        for(char ch : s){
            mp[ch]++;
        }
        int maxVowelFreq = 0 , maxConsFreq=0 ;
        for(auto& ele : mp){
            if(st.find(ele.first)!=st.end() ){
                maxVowelFreq= max(maxVowelFreq, ele.second);
            }else{
                maxConsFreq = max(maxConsFreq , ele.second);
            }
        }
        return maxConsFreq + maxVowelFreq;
    }
};