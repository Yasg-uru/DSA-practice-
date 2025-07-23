class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
             pq.push({c,'c'});
        }
        string res="";
        while(not pq.empty()){
            auto [count ,character]=pq.top();
            pq.pop();
            //after removing this we need to keep track 
            int n=res.size();
            if(n>=2 and res[n-1]==character and res[n-2]==character){
                if(pq.empty()){
                    break;
                }
                auto [c,ch]=pq.top();
                pq.pop();
                c--;
                res.push_back(ch);
                if(c>0){
                    pq.push({c,ch});
                }
            }else{
                res.push_back(character);
                count--;
                // pq.push({count,character});
            }
            if(count>0){
                pq.push({count,character});
            }

        }
        return res;
    }
};