class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int , set<char>>mp;
        for(int i =0 ;i<rings.size()-1;i++){
            char ch = rings[i];
            int ring_number = rings[i+1]-'0';
            mp[ring_number].insert(ch);
        }
        int count =0 ;
        for(auto& ele : mp){
            if(ele.second.size()==3){
                count++;
            }
        }
        return count ;
    }
};