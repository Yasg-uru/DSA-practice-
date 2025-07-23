class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string , string>mp;
        for(int i=0;i<messages.size();i++){
            string message = messages[i];
            string sender = senders[i];
            if(mp.find(sender)==mp.end()){
                mp[sender]= message;
            }else {
                mp[sender] = mp[sender] + " "+message;
            }
        }
        string ans = "";
        int maxLength = 0 ;
        for(auto& ele : mp){
            string sender = ele.first;
            string message = ele.second;
            if(maxLength<message.length()){
                ans= sender;
                maxLength = message.length();
            }else if(maxLength==message.length() and ans<sender){
                ans= sender;
                
            }
        }
        return ans ;
    }
};