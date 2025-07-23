class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        //now we are using hashmap to store values and indexes of the particulare element
        unordered_map<int,int>mp;
        for(int i:deck){
           mp[i]++;

        }
        int res=0;
        for(auto i=mp.begin(); i!=mp.end();i++){
            res=__gcd(i->second,res);
        }
        return res>1;
    }
};