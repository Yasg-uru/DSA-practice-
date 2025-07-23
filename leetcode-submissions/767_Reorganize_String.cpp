class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int >mp;

        for(char ch:s){
            mp[ch]++;

        }
        priority_queue<pair<int ,char>>pq;
        for(auto ele :mp){
            pq.push({ele.second ,ele.first});
        }
        string ans ="";
        while(not pq.empty()){
            auto curr=pq.top();
            pq.pop();
            char character =curr.second ;
            int count =curr.first;
            if( not ans.empty() and character==ans.back() ){
                if(pq.empty()){
                    return "";
                }
                char nextCharacter=pq.top().second;
                int newchCount =pq.top().first;
                pq.pop();
                ans+=nextCharacter;
                newchCount--;
                if(newchCount>0){
                    pq.push({newchCount,nextCharacter});
                }
                pq.push({count,character});

            }else {
                ans+=character;
            count--;
            if(count>0){
                pq.push({count , character});
                
            }
            }
            
        }
        return ans ;
    }
};