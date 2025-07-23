class Solution {
public:
struct CompareFirst{

bool operator()(const pair<int,int>&p1 , const pair<int,int>&p2) const{
    return p1.first<p2.first;
}
};
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        set<pair<int,int>,CompareFirst>s1;
        set<pair<int,int>,CompareFirst>s2;
        for(auto& item : items1){
            s1.insert({item[0],item[1]});
        }
        for(auto& item:items2){
            s2.insert({item[0],item[1]});
        }
        vector<vector<int>>ans;
        //after inserting the items we need to find the similar items 
        if(s1.size()>=s2.size()){
            for(auto ele:s1){
                auto it =s2.find({ele.first,0});
                if(it!=s2.end()){
                    ans.push_back({it->first,ele.second+it->second});
                }else {
                    ans.push_back({ele.first,ele.second});
                }
            }
        }else {
            for(auto ele:s2){
                auto it =s1.find({ele.first,0});
                if(it!=s1.end()){
                    ans.push_back({it->first,ele.second+it->second});
                }else {
                    ans.push_back({ele.first,ele.second});
                }
            }
        }
        return ans ;

    }
};