class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int , int >mp;
        int n = x.size();
        for(int i =0 ;i<n;i++){
            if(mp.find(x[i])!=mp.end()){
                mp[x[i]]= max(mp[x[i]], y[i]);
            }else{
                mp[x[i]]= y[i];
            }
        }
        if(mp.size()<3){
            return -1;
        }
        vector<int>t;
        for(auto& ele : mp){
            t.push_back(ele.second);
        }
        sort(t.begin(), t.end());
        reverse(t.begin(), t.end());
        int ans =0 ;
        
        for(int i =0 ;i<3;i++){
            ans+=t[i];
        }
        return ans ;
    }
};