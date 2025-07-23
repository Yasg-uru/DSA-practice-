class Solution {
public:
    long long findScore(vector<int>& nums) {
        // we need to use set because it doesnot destroy our order of an element 
        set<pair<int,int>>s;
        for(int i=0;i<nums.size();i++){
            s.insert({nums[i],i});
        }
        int score=0;

        //after that we need to traverse the loop until our set is not empty 
        while(not s.empty()){
            //choosing the smallest value
            auto smallest=*s.begin();
            s.erase(smallest);
            int index=smallest.second ;
            int element=smallest.first;
            score+=element;
            if(index+1<=nums.size()){
                pair<int,int>p_left={nums[index+1],index+1};
                if(s.find(p_left)!=s.end()){
                    s.erase(p_left);
                }
            }
             if(index-1>=0){
                pair<int,int>p_right={nums[index-1],index-1};
                if(s.find(p_right)!=s.end()){
                    s.erase(p_right);
                }
            }


        }
        return score;
    }
};