class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans =0;

       priority_queue<int>pq;
       for(int gift:gifts){
        pq.push(gift);
       }
       while(k--){
        int top=pq.top();
        pq.pop();
        int square_root=(int)sqrt(top);
    pq.push(square_root);
       }
       while(not pq.empty()){
        ans+=pq.top();
        pq.pop();
       }
       return ans ;
    }
};