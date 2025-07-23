class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;

        }
        int cnt=0;

        for(string str:arr){
            if(mp[str]==1){
                cnt++;
            }
            if(cnt==k){
                return str;
            }
        }

       
        
        return "";
    }
};