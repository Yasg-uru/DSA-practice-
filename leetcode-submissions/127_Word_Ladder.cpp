class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(begin(wordList), end(wordList));
        if(st.find(endWord)==st.end()){
            return 0 ;
            
        }
        queue<pair<string , int>>q;
        q.push({beginWord , 1});
        while(not q.empty()){
            auto  [ word , depth]= q.front();
            q.pop();
            if(word==endWord){
                return depth;
            }
           
            for(int i =0 ;i<word.size();i++){
                 string temp = word;
                for(char ch = 'a';ch<='z';ch++){
                    temp[i]= ch;
                    if(st.find(temp)!=st.end()){
                        q.push({temp , depth+1});
                        st.erase(temp);
                    }
                }
            }
                
        }
        return 0 ;
    }
};