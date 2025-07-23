class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(begin(citations), end(citations));
        reverse(begin(citations ), end(citations));
        int n = citations.size();
        for(int i =0 ;i<n;i++){
            if(citations[i]<i+1){
                return i;
            }
        }
        return n;
    }
};