class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        for(int i =2;i<n;i++){
            if(n%i==0) return false;
        }
        return true ;
    }
    long long sumOfLargestPrimes(string s) {
        priority_queue<int>pq;
        unordered_set<int>st;
        for(int i =0;i<s.length();i++){
            for(int j = i;j<s.length();j++){
                int num =stoi(s.substr(i , j-i+1));
                if(isPrime(num)){
                    st.insert(num);
                }
            }
        }
        for(auto&ele : st) {
            pq.push(ele);
        }
        int k=3;

        int ans =0;
        while(k>0 and not pq.empty()){
            ans+=pq.top();
            pq.pop();
            k--;
        }
        return ans ;
    }
};