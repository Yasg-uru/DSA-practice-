class Solution {
public:
    int minimumPushes(string word) {
        int cnt=1;
        int size=word.size();
        int ans=0;

        for(int i=0;i<size;i+=8){
            ans+=cnt*min(8,size-i);
            cnt++;
        }
        return ans;
    }
};