class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int minindex=INT_MAX;
        //now we need to create a unordered map for storing indexes of the elements
        unordered_map<string,int>mp;
        vector<string>result;
        for(int i=0;i<list1.size();i++){
            mp[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++){
            if(mp.count(list2[i])){
                int indexsum=i+mp[list2[i]];
                if(indexsum<minindex){
                    minindex=indexsum;
                    result.clear();
                    result.push_back(list2[i]);
                }else if(indexsum==minindex){
                     result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};