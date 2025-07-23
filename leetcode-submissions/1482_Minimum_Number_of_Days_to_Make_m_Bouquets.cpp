class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        set<int>s(bloomDay.begin(),bloomDay.end());
        int count=0;
int finalans=0;

        for(auto ele:s){
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=ele){
                    count++;
                    if(count==k){
                        finalans++;
                        count=0;
                    }
                    if(finalans==m){
                        return ele;
                    }
                }else{
                    count=0;
                    break;
                }
            }

        }
        return -1;
    }
};