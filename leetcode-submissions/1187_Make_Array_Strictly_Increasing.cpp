class Solution {
public:
    map<pair<int,int>,int>mp;
    int solve(int i ,vector<int>& arr1, vector<int>& arr2, int prev ){
        if(i>=arr1.size()) return 0 ;
        int result1= 1e9+9;
        if(mp.count({i,prev})) return mp[{i, prev}];
        if(arr1[i]>prev){
            result1= solve(i+1, arr1, arr2, arr1[i]);
        }
        int result2= 1e9+9;
        auto it = upper_bound(begin(arr2), end(arr2), prev);
        if(it!=end(arr2)){
            int j = it-begin(arr2);
            prev = arr2[j];
            result2= 1+solve(i+1,arr1, arr2, prev );
        }
        return mp[{i,prev}]= min(result1, result2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        
        mp.clear();

        int result = solve(0 , arr1, arr2, INT_MIN);
        if(result==1e9+9){
            return -1;
        }
        return result ;
    }
};