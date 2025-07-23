class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int  , vector<int> >mp;
        for(auto& piece:pieces){
            mp[piece[0]]= piece;
        }
        int n = arr.size();
        int i =0 ;
        while(i<n){
            if(mp.find(arr[i])==mp.end()){
                return false;
            }else{
                vector<int>vec = mp[arr[i]];
                // now try to compare all the elements 
                int j =0 ;
                for(int j=0 ;j<vec.size() && i<n;j++){
                    if(vec[j]!=arr[i]){
                        return false;
                    }
                    i++;
                }
            }
            
        }
        return true ;
    }
};