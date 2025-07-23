class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int>s;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){ s.insert(i);}
        }
        vector<int>ans(boxes.size(),0);
        for(int i=0;i<boxes.size();i++){
            int moves=0;
            for(auto index:s){
                moves+=abs(i-index);
            }
            ans[i]=moves;
        }
        return ans ;
    }
};