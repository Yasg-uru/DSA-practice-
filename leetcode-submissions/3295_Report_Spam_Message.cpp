class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string>s(bannedWords.begin(),bannedWords.end());
        int count =0;
        for(int i=0;i<message.size();i++){
                if(s.count(message[i])){
                    count++;
                }
        }
        cout<<"cout:"<<count;
return count>=2?true :false;
    }
};