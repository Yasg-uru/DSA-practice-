class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int >mp;
        for(int i =0 ;i<arr.size();i++){
            mp[arr[i]]++;
        }
        unordered_set<int >st;
        for(auto& ele : mp){
            if(st.count(ele.second)) return false;
            st.insert(ele.second);
        }
        return true ;
    }
};