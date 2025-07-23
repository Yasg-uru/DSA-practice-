class Solution {
public:
    int partitionString(string s) {
        int count =0 ;
        unordered_set<char>st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(st.count(s[i])){
                count++;
                st.clear();

            }
            st.insert(s[i]);
        }
        if(not st.empty()){
            count+=1;
        }
        return count ;
    }
};