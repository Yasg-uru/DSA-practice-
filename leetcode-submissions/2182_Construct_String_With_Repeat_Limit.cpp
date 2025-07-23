class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        priority_queue<int,int > pq;

        for(int i=0;i<26;i++){
       if(freq[i]>0){
         pq.push(make_pair(i,freq[i]));
       }

        }
        string ans ="";
        while(not pq.empty(){
            auto curr=pq.top();
            pq.pop();
            //after this we need to insert 
            int count =curr.second ;
            char  ch='a'+curr.first;
            int use=min(count ,repeatLimit );
            ans.append(use,ch);
            
        }
    }
};