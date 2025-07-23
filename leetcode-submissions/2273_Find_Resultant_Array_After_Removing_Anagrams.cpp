class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<bool>canTake(words.size(), true );
        set<int>st;
        for(int i =0 ;i<words.size();i++){
                string i_th_word  =words[i];
                sort(i_th_word.begin(), i_th_word.end());
                if(not canTake[i]) continue ;
            for(int j = i+1 ;j<words.size();j++){
                string j_th_word = words[j];
                sort(j_th_word.begin(), j_th_word.end());
                if(not canTake[j]) continue ;
                if(i_th_word ==j_th_word){
                    canTake[j] = false;
                }
               
            }
        }
        
        vector<string>ans ;
        for(int i =0 ;i<canTake.size();i++){
            if(canTake[i]){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }

};