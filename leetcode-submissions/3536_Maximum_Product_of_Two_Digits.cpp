class Solution {
public:
    int maxProduct(int n) {
       priority_queue<int>pq;
        while(n){
            int lastDigit = n%10;
        pq.push(lastDigit);
            n/=10;
        }
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        return first*second ;
    }
};