class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        sort(hand.begin(),hand.end());

        unordered_map<int,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }

        while(not mp.size()>0){
            int p=mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp[p+i]>0){
mp[p+i]--;
if(mp[p+i]==0){
    mp.erase(p+i);
}

                }else{
                    return false;
                }
            }

        }
        return true;
    }
};